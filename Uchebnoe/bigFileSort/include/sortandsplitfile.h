#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <atomic>
#include <thread>
#include <fstream>
#include <filesystem>
#include "arrayThreadSafe.h"

using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;
namespace   fs = std::filesystem;

namespace bigFileSort {

class SortAndSplitFile
{
    const size_t tmpBufSize = 5 * 1024 * 1024;

    ArrayThreadSafe<std::vector<std::string>, 4> arrayThreadSafe;

    const std::string &fileName;
    const std::string &outPath;

    std::atomic<size_t> fileCounter = 0;
    std::atomic<size_t> maxCounter = 0;
    std::atomic<size_t> counter = 0;

public:
    explicit SortAndSplitFile(const std::string &fileName, const std::string &outPath) noexcept;
    void run() noexcept;

private:
    void read() noexcept;
    void out() noexcept;
    void sort() noexcept;

};

}
