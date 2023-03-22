class Solution {
public:
    int bs(vector<int> &num, int startPos, int searchValue){

        if (num[startPos] < searchValue){
            return -1;
        }

        int right = num.size() - 1;


        while(startPos <= right){
            int mid = startPos + (right - startPos) / 2.0;

            if (num[mid] < searchValue){
                right = mid - 1;
            }
            else{
                startPos = mid+1;
            }
        }
        return startPos - 1;
    }
    
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDistance = 0;

        for(int i = 0; i < nums1.size() && i < nums2.size(); ++i){
            auto nums2Pos = bs(nums2, i, nums1[i]);//nums2.rend() - lower_bound(nums2.rbegin(), nums2.rend(), nums1[i]);//
            //cout << i << " " << nums2Pos << endl;
            if (nums2Pos != -1){
                
                maxDistance = max(maxDistance, (int)nums2Pos - i);

            }
        }

        return maxDistance;
    }
};