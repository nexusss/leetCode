#include <iostream>

#include "include/sortandsplitfile.h"
#include "include/generatefile.h"
#include "include/outmerge.h"
#include "threadpool.h"
#include "Test.h"

using namespace bigFileSort;
using readType = std::string;

const std::string outPath = "out";
const std::string testFileName = "test_file.txt";


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



//ThreadPool tp(3, );



void fileSortCheck(string fileName){
    const string outFileName = "result/" + fileName;

    ifstream stream;
    stream.open(fileName);
    size_t fileInCounter = 0;
    if(stream.is_open()){

        string str;
        while(stream){
            stream >> str;
            fileInCounter++;
        }
    }
    else{
        std::cout << "file " << fileName << " not open " << std::endl;
    }

    std::cout << "in  " << fileInCounter <<std::endl;

    stream.close();
    stream.open(outFileName);
    size_t fileResCounter = 0;
    if(stream.is_open()){

        string str;
        while(stream){
            stream >> str;
            fileResCounter++;
        }
    }
    else{
        std::cout << "file " << outFileName << " not open " << std::endl;
    }

    stream.close();

    std::cout << "res " << fileResCounter <<std::endl;

    size_t fileOutCounter = 0;

    for (auto & p : fs::directory_iterator("out")){
        ifstream stream;
        stream.open(p.path());

        if (stream.is_open()){
            string str;
            while(stream){
                stream >> str;
                fileOutCounter++;
            }
        }
        else{
            std::cout << "could not open the file " << p.path() << std::endl;
        }
    }

    std::cout << "out " << fileOutCounter <<std::endl;

    std::cout << "eq " <<(fileResCounter == fileInCounter) << std::endl;
}

int main()
{

//fileSortCheck(testFileName);
//return 0;
/*auto start = std::chrono::high_resolution_clock::now();
external_sort(testFileName);


auto end = std::chrono::high_resolution_clock::now();
auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
std::cout << "done " << formatDuration(delta) << std::endl;
return 0;*/
    //generateFile(testFileName, 100);
    auto startApp = std::chrono::high_resolution_clock::now();

    {

        SortAndSplitFile sasFile(testFileName, outPath);
        auto start = std::chrono::high_resolution_clock::now();
        sasFile.run();

        auto end = std::chrono::high_resolution_clock::now();
        auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "done " << formatDuration(delta) << std::endl;
        //return 0;
    }
    {
        OutMerge outMerge(testFileName, outPath);
        auto start = std::chrono::high_resolution_clock::now();

        outMerge.run();

        auto end = std::chrono::high_resolution_clock::now();
        auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "done " << formatDuration(delta) << std::endl;
    }

    auto endApp = std::chrono::high_resolution_clock::now();
    auto deltaApp = std::chrono::duration_cast<std::chrono::milliseconds>(endApp - startApp);
    std::cout << "done " << formatDuration(deltaApp) << std::endl;
fileSortCheck(testFileName);
    return 0;
}
