#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findDistance(string input, string pattern){
    vector<vector<int>> distance;
    size_t inputSize = input.size() + 1;
    size_t patternSize = pattern.size() + 1;
    distance.resize(inputSize);

    for(auto &dist: distance){
        dist.resize(patternSize);
    }

    for(size_t i = 0; i < inputSize; ++i){
        distance[i][0] = i;

    }
    for(size_t j = 0; j < patternSize; ++j){
        distance[0][j] = j;
    }

    for(size_t i = 1; i < inputSize; ++i){
        for(size_t j = 1; j < patternSize; ++j){
            auto minAB = min(distance[i-1][j] + 1, distance[i][j-1] + 1);
            int cost = input[i - 1] != pattern[j - 1] ? 1 : 0;

            distance[i][j] = min(minAB, distance[i-1][j-1] + cost);
        }
    }
    cout << "distance" << distance[inputSize - 1][patternSize - 1] << endl;
    return distance[inputSize - 1][patternSize - 1];
}

struct Fuzzy{
    int distance;
    string word;
    Fuzzy(int distance, string word):distance(distance),word(word){}
    friend bool operator<(const Fuzzy &f, const Fuzzy &f2){
        return f.distance < f2.distance;
    }
};
class myComparator
{
public:
    int operator() (const Fuzzy& p1, const Fuzzy& p2)
    {
        return p1.distance > p2.distance;
    }
};
void fuzzySearch(const vector<string> &input,const string &pattern){
    priority_queue <Fuzzy, vector<Fuzzy>,myComparator > heap;

    for(auto &inp: input){
        heap.emplace(findDistance(inp,pattern), inp);
    }

    for (size_t i = 0; i < 5 && !heap.empty(); i++){
        auto top = heap.top();
        heap.pop();
        cout << top.distance << " " << top.word << endl;
    }
}

int main()
{
    vector<string> input = {"Lorem", "Ipsum", "is", "simply", "dummy", "text", "of", "the", "printing", "and", "typesetting", "industry.",
                            "Lorem", "Ipsum", "has", "been", "the", "industrys", "standard", "dummy", "text", "ever", "since", "the", "1500s",
                            "when", "an", "unknown", "printer", "took", "a", "galley", "of", "type", "and", "scrambled", "it", "to", "make",
                            "a", "type", "specimen", "book.", "It", "has", "survived", "not", "only", "five", "centuries", "but", "also",
                            "the", "leap", "into", "electronic", "typesetting", "remaining", "essentially", "unchanged.", "It", "was",
                            "popularised", "in", "the", "1960s", "with", "the", "release", "of", "Letraset", "sheets", "containing", "Lorem",
                            "Ipsum", "passages", "and", "more", "recently", "with", "desktop", "publishing", "software", "like", "Aldus",
                            "PageMaker", "including", "versions", "of", "Lorem", "Ipsum", "lrem", "rem", "lreom"};

    fuzzySearch(input, "rem");
    //fuzzySearch({"gibraltar"}, "labrador");
    cout << "Hello World!" << endl;
    return 0;
}
