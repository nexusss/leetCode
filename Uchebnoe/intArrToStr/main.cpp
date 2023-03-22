#include <iostream>
#include <vector>
#include <string>

using namespace std;

string rangeToString(const vector<int>& arr) {
    if (arr.empty()) {
        return "";
    }

    vector<pair<int, int>> ranges;

    int start = arr[0];
    int end = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == end + 1) {
            end = arr[i];
        } else {
            ranges.push_back({start, end});
            start = end = arr[i];
        }
    }

    ranges.push_back({start, end});

    string result = to_string(ranges[0].first);

    for (int i = 1; i < ranges.size(); i++) {
        if (ranges[i].first == ranges[i-1].second + 1) {
            result += "-";
        } else {
            result += ",";
        }

        result += to_string(ranges[i].second);
    }

    return result;
}

int main() {
    vector<int> arr = {1,4,5,2,3,9,8,11,0};

    string result = rangeToString(arr);

    cout << result << endl; // prints "0-5,8-9,11"

    return 0;
}
