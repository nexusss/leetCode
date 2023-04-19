class NumArray {
    vector<int> segmentTree;
    int arrsize;

    void build(const vector<int> &num, int node, int left, int right){

        if(left == right){
            segmentTree[node] = num[left];
        }
        else{
            auto mid = left + (right - left) / 2;
            build(num, 2 * node + 1 , left, mid);
            build(num, 2 * node + 2, mid + 1, right);
            segmentTree[node] = segmentTree[2 * node + 1] + segmentTree[2 * node + 2];
        }
        //cout << "b " << node << " " << segmentTree[node] << endl;
    }

    int getHelper(int node, int left, int right, int calcLeft, int calcRight){
        if (left > calcRight  || calcLeft > right ) {
            return 0;
        }
        if(left <= calcLeft and right >= calcRight){
            return segmentTree[node];
        }
        else{
            auto mid = calcLeft + (calcRight - calcLeft) / 2;
            auto p1 = getHelper(2 * node + 1, left, right, calcLeft, mid);
            auto p2 = getHelper(2 * node + 2, left, right, mid + 1, calcRight);
            //cout << p1 << " " << p2 << endl;
            return p1 + p2;
        }
    }

    void updateHelper(int node, int pos, int left, int right, int val){
        if(pos >= left and pos <= right) {
            if (left == right) {
                segmentTree[node] = val;
            } else {
                auto mid = left + (right - left) / 2;
                updateHelper(2 * node + 1, pos, left, mid, val);
                updateHelper(2 * node + 2, pos, mid + 1, right, val);
                segmentTree[node] = segmentTree[2 * node + 1] + segmentTree[2 * node + 2];
            }
        }
    }
public:
    NumArray(vector<int>& nums) {
        segmentTree.resize(nums.size() * 4, 0);
        build(nums, 0, 0, nums.size() - 1);
        arrsize = nums.size();
    }
    
    void update(int index, int val) {
        updateHelper(0, index, 0, arrsize - 1, val);
    }
    
    int sumRange(int left, int right) {
        return getHelper(0, left, right, 0, arrsize - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */