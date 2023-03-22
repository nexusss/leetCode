#include "generatefile.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <filesystem>

std::string generateString(){
    auto res = (std::rand() % 256) + 1;
    std::string str(res, ' ');

    for(auto &c: str){
        c = (std::rand() % 26) + 'a';
    }
    return str;
}

void generateFile(const std::string &fileName, uint64_t gb){
    std::srand(std::time(nullptr));

    std::ofstream outfile;
    outfile.open(fileName);

    if (outfile.is_open()) {

        const uint64_t sizeInBytes = gb * 1024 * 1024 * 1024;
        std::cout << "file " << fileName << " start generate " << sizeInBytes << " bytes" << std::endl;
        uint64_t currentSizeInBytes = 0;

        while (currentSizeInBytes < sizeInBytes) {
            auto writeStr = generateString();
            outfile << writeStr << "\n";
            currentSizeInBytes += writeStr.size() + 1;
        }
        outfile.close();
        std::cout << "done " << std::filesystem::file_size(fileName) << " bytes" << std::endl;
    }
    else{
        std::cout << "file " << fileName << " not open" <<std::endl;
    }

}
