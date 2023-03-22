#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <thread>
#include <memory>
#include "ringbuffer.h"
#include <iostream>
namespace bigFileSort {

namespace   fs = std::filesystem;

using rb = RingBuffer<std::string,2 * 1024 * 1024>;
using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;
using readType = string;


class OutMerge
{
    vector <ifstream> ifs;
    vector <std::unique_ptr<rb>> rbs;
    RingBuffer<readType, 10 * 1024 * 1024> outRbs;

    std::atomic<int64_t> mergeCounter = 0;

    const std::string resultPath = "result";
    const std::string &fileName;
    const std::string &inPath;

public:
    explicit OutMerge(const std::string &fileName, const std::string &inPath) noexcept;

    void run() noexcept;

private:
    void out() noexcept;
    void merge() noexcept;
    void read() noexcept;
};

}
