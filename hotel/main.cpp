#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{

    vector <vector<int>> rooms;

    rooms.push_back({1,2});
    rooms.push_back({1,3});
    rooms.push_back({3,4});
    rooms.push_back({3,6});
    rooms.push_back({2,5});
    rooms.push_back({2,4});
    rooms.push_back({2,3});
    rooms.push_back({1,4});

    unordered_map <int, int> arriving;
    unordered_map <int, int> leaving;

    int minDay = std::numeric_limits<int>::max(), maxDay = 0;

    for(auto &room: rooms){
        arriving[room[0]] += 1;
        leaving[room[1]] += 1;
        if (minDay > room[0]){
            minDay = room[0];
        }
        if (maxDay < room[1]){
            maxDay = room[1];
        }
    }

    int res = 0;
    int count = 0;
    for(int i = minDay; i <= maxDay; ++i){
        count += arriving[i];
        count -= leaving[i];
        cout << "count " << count << endl;
        if (count > res){
            res = count;
        }
    }

    cout << "res " << res << endl;
    return 0;
}
