#ifndef TEST_H
#define TEST_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <thread>
#include <vector>

const int chunk_size = 2 * 1024 * 1024;  // 2MB
const int max_mem = 2 * 1024 * 1024 * 1024;  // 2GB

void sort_chunk(const std::string& filename, int start, int end) {
  std::ifstream in(filename, std::ios::binary);
  in.seekg(start);
  std::vector<int> data(chunk_size / sizeof(int));
  in.read(reinterpret_cast<char*>(data.data()), (end - start));
  int size = in.gcount() / sizeof(int);
  std::sort(data.begin(), data.begin() + size);
  in.close();
  std::ofstream out(filename + "." + std::to_string(start), std::ios::binary);
  out.write(reinterpret_cast<char*>(data.data()), size * sizeof(int));
  out.close();
}

void merge(const std::string& filename, const std::vector<int>& chunk_starts, int chunk_size) {
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
  std::vector<std::ifstream> streams(chunk_starts.size());
  for (int i = 0; i < chunk_starts.size(); ++i) {
    streams[i].open(filename + "." + std::to_string(chunk_starts[i]), std::ios::binary);
    int value;
    if (streams[i].read(reinterpret_cast<char*>(&value), sizeof(int))) {
      pq.push({value, i});
    }
  }
  std::ofstream out(filename + ".sorted", std::ios::binary);
  while (!pq.empty()) {
    auto [value, i] = pq.top();
    pq.pop();
    out.write(reinterpret_cast<char*>(&value), sizeof(int));
    if (streams[i].read(reinterpret_cast<char*>(&value), sizeof(int))) {
      pq.push({value, i});
    }
  }
  out.close();
  for (auto& stream : streams) {
    stream.close();
  }
}

void external_sort(const std::string& filename) {
  // Step 1: Divide the large file into smaller chunks that fit into memory.
  std::ifstream in(filename, std::ios::binary | std::ios::ate);
  int file_size = in.tellg();
  in.close();
  int num_chunks = file_size / max_mem + 1;
  std::vector<int> chunk_starts(num_chunks);
  for (int i = 0; i < num_chunks; ++i) {
    chunk_starts[i] = i * max_mem;
  }
  std::vector<std::thread> threads(num_chunks);
  for (int i = 0; i < num_chunks; ++i) {
    int start = chunk_starts[i];
    int end = std::min(start + max_mem, file_size);
    threads[i] = std::thread(sort_chunk, filename, start, end);
  }
  for (auto& thread : threads) {
    thread.join();
  }

  // Step 2: Merge the sorted chunks into a single sorted file.
  for (int i = 1; i < num_chunks; ++i) {
    chunk_starts[i] += chunk_size;
  }
  merge(filename, chunk_starts, chunk_size);
}

#endif // TEST_H
