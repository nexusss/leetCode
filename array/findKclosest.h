#ifndef FINDKCLOSEST_H
#define FINDKCLOSEST_H
vector<int> findKClosest(vector<int> arr, int x, int k){
    int left = 0;
    int right = arr.size();
    int medium;
    while (left <= right){
        medium = left + (right - left) / 2;
        auto tmp = arr[medium];
        if (arr[medium] == x){
            break;
        }
        else if(arr[medium] > x){
            right = medium - 1;
        }
        else if(arr[medium] < x){
            left = medium + 1;
        }
    }
    left = medium - 1;
    right = medium;

    while (k-- > 0){
        if(left < 0 || (right < arr.size() && abs(arr[left] - x) > abs(arr[right] - x))){
                   right++;
               }
               else{
                   left--;
               }
            }

    return vector<int>(arr.begin() + left + 1, arr.begin() + right);
}

#endif // FINDKCLOSEST_H
