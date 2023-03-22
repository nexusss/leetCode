#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;
using namespace std;

void swap(vector<int>& arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function returns the
// minimum number of swaps
// required to sort the array
int minSwaps(vector<int> arr, int N)
{
    int ans = 0;
    vector<int> temp = arr;

    // Hashmap which stores the
    // indexes of the input array
    map<int, int> h;

    sort(temp.begin(), temp.end());
    for (int i = 0; i < N; i++) {
        h[arr[i]] = i;
    }
    for (int i = 0; i < N; i++) {
        // This is checking whether
        // the current element is
        // at the right place or not
        if (arr[i] != temp[i]) {
            ans++;
            int init = arr[i];

            // If not, swap this element
            // with the index of the
            // element which should come here
            swap(arr, i, h[temp[i]]);

            // Update the indexes in
            // the hashmap accordingly
            h[init] = h[temp[i]];
            h[temp[i]] = i;
        }
    }
    return ans;
}

// Driver code
class INteger{
    int num;
public:
    INteger(){
        num = 0;
        cout << "1";
    }
    INteger(int arg){
        num = arg;
        cout << "2";
    }
    int getValue(){
        cout << "3";
        return num;
    }
};

int main()
{
    vector<int> arr = { 3, 1, 2 };
    int n = (sizeof(arr) / sizeof(int));
    cout << minSwaps(arr, n) << endl;
INteger i;
i = 10;
cout << i.getValue();
    return 0;
}
