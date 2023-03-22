class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (arr.size() <= k){
            return arr;
        }
        
        if ( x <= arr[0]){
            return vector<int>(arr.begin(), arr.begin() + k);
        }
        
        if ( x >= arr.back()){
            return vector<int>(arr.end() - k, arr.end() );
        }
        
        int left = 0;
        int right = arr.size() - 1;
        
        while(left < right){
            int mid = left + (right - left)/2;
            if (arr[mid] == x){
                left = right = mid;
                break;
            }
            if (x < arr[mid]){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }

        if (left > 0 && (abs(arr[left - 1] - x) == abs(arr[left] - x) && arr[left - 1] < arr[left]) or (abs(arr[left - 1] - x) < abs(arr[left] - x)) ){
            left--;
        }
        
        right = left;
        
        
        for(int i = 0; right - left + 1 < k; i++){
            if (right + 1 >= arr.size()){
                left--;
            }
            else if (left - 1 < 0){
                right++;
            }
            else if(abs(arr[left - 1] - x) > abs(arr[right + 1] - x)){
                right++;
            }
            else{
                left--;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};