#include "outmerge.h"
#include <queue>
#include <iostream>

namespace bigFileSort {

void OutMerge::out() noexcept{
    ofstream outfile;
    fs::remove_all(resultPath);
    fs::create_directory(resultPath);
    const string outFileName = resultPath + "/" + fileName;

    std::cout << "start out" << std::endl;

    outfile.open(outFileName);
    if(outfile.is_open()){
        std::cout << "open the file " << outFileName << std::endl;
        string value;
        while(outRbs.top(value)){
            outfile << std::move(value) << "\n";

        }
    }
    else{
        std::cout << "not open the file " << outFileName << std::endl;
    }

    std::cout << "out done" << std::endl;

}

void OutMerge::merge() noexcept{
    using ofsIndex = size_t;
    using pqType = std::pair<readType, ofsIndex>;

    auto f = [](const pqType &a,const pqType &b){ return a.first > b.first;};
    std::priority_queue <pqType, vector<pqType>, decltype (f)> pq(f);

    std::cout << "start merge" << std::endl;

    for(size_t i = 0, end = rbs.size(); i < end; ++i){
            string str;
            if( rbs[i]->top(str)){
                pq.emplace(std::move(str), i);
            }
    }

    int counter = 0;
    string str;
    std::cout << pq.size() << std::endl;
    while(!pq.empty() or mergeCounter > 0){
        auto [value, index] = std::move(pq.top());
        auto tmpIndex = index;
        if(!outRbs.isFullWait()){
            outRbs.pushBack(std::move(value));
            pq.pop();


            if( rbs[tmpIndex]->top(str)){
                pq.emplace(std::move(str), index);
            }
        }
        else{
            pq.pop();
        }
    }
    outRbs.setNoMoreData();
    std::cout << "merge done " << counter << std::endl;
}

void OutMerge::read() noexcept{
    std::cout << "start read" << std::endl;
    vector<int64_t> counters(rbs.size());
    string tmp;
    while(mergeCounter > 0){
         for(size_t i = 0, end = ifs.size(); i < end; ++i){
            if ( ifs[i].eof() && !rbs[i]->getNoMoreData()){
                rbs[i]->setNoMoreData();
                mergeCounter--;
            }
            else{
                while(!rbs[i]->isFull()){

                    ifs[i] >> tmp;
                    rbs[i]->pushBack(std::move(tmp));
                }

            }
        }
    }

    std::cout << "read done" << std::endl;
}

OutMerge::OutMerge(const std::string &fileName, const std::string &inPath) noexcept :
    fileName(fileName), inPath(inPath)
{

}

void OutMerge::run() noexcept{
    std::cout << "run" << std::endl;

    for (auto & p : fs::directory_iterator(inPath)){
        ifstream stream;
        stream.open(p.path());

        if (stream.is_open()){
            ifs.emplace_back(std::move(stream));

            rbs.emplace_back(std::make_unique<rb>());
            mergeCounter++;
        }
        else{
            std::cout << "could not open the file " << p.path() << std::endl;
        }
    }

    std::cout << "mergeCounter " << mergeCounter << std::endl;
    std::thread outThread(&OutMerge::out, this);
    std::thread mergeThread(&OutMerge::merge, this);
    std::thread readThread{&OutMerge::read, this};

    outThread.join();
    mergeThread.join();
    readThread.join();
}

}
