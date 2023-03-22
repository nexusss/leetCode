#include "sortandsplitfile.h"
#include <algorithm>

namespace bigFileSort {
std::string formatDuration( std::chrono::milliseconds ms ) {
    using namespace std::chrono;
    auto secs = duration_cast<seconds>(ms);
    ms -= duration_cast<milliseconds>(secs);
    auto mins = duration_cast<minutes>(secs);
    secs -= duration_cast<seconds>(mins);
    auto hour = duration_cast<hours>(mins);
    mins -= duration_cast<minutes>(hour);

    std::stringstream ss;
    ss << hour.count() << " Hours : " << mins.count() << " Minutes : " << secs.count() << " Seconds : " << ms.count() << " Milliseconds";
    return ss.str();
}
void SortAndSplitFile::read() noexcept
{
    //std::cout << "start read" << std::endl;
    std::ifstream myfile;
    myfile.open(fileName);
    if(myfile.is_open()){

        std::cout << "open the file " << fileName << std::endl;
        size_t iter = 0;
        while(myfile) {

            auto index = arrayThreadSafe.writeIndex();

            auto &inArray = arrayThreadSafe.getValue(index);

            while (myfile and iter < inArray.size()) {
                myfile >> inArray[iter];
                ++iter;
            }

            if (iter < inArray.size()){
                inArray.resize(iter);
            }
            arrayThreadSafe.sortPushBack(index);
            iter = 0;

        }
    }
    arrayThreadSafe.setNoMoreData();

    std::cout << "read done " << std::endl;
}

void SortAndSplitFile::sort() noexcept
{
    std::cout << "start sort" << std::endl;
    std::ofstream outfile;
    while(true){
        const std::string outFileName = outPath + "/" + fileName + "_" + std::to_string(++fileCounter);
        auto index = arrayThreadSafe.sortIndex();
        if (index == -1){
            break;
        }
        outfile.open(outFileName);
        if (outfile.is_open()){
            auto &sortArray = arrayThreadSafe.getValue(index);
            counter++;
            maxCounter = std::max(counter.load(), maxCounter.load());
            std::sort(sortArray.begin(), sortArray.end());
            for(auto &str: sortArray) {
                outfile << str << "\n";
            }
            counter--;
            arrayThreadSafe.writePushBack(index);

        }
        outfile.close();
    }
    std::cout << "sort done " << maxCounter << std::endl;
}

SortAndSplitFile::SortAndSplitFile(const std::string &fileName, const std::string &outPath) noexcept :
    fileName(fileName), outPath(outPath)
{
    for(size_t i = 0; i < arrayThreadSafe.size(); ++i){
        arrayThreadSafe.getValue(i).resize(tmpBufSize);
        for(auto &str: arrayThreadSafe.getValue(i)){
            str.reserve(255);
        }
    }

}

void SortAndSplitFile::run() noexcept
{
    std::cout << "run" << std::endl;

    fileCounter = 0;

    fs::remove_all(outPath);
    fs::create_directory(outPath);

    const unsigned int maxCpu = std::thread::hardware_concurrency();
    vector<std::thread> threadPool;
    std::thread readThread{&SortAndSplitFile::read, this};
    for(unsigned int i = 0; i < 4; ++i){
        threadPool.emplace_back(&SortAndSplitFile::sort, this);

    }

    for(auto &thr: threadPool){
        thr.join();
    }
    readThread.join();
}
}
