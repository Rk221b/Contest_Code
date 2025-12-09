/*
Problem Link: https://leetcode.com/problems/range-sum-query-mutable/description/?envType=problem-list-v2&envId=segment-tree
*/

class NumArray {

    vector<int> segmentTree;
    int n;

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4*n);

        // build SegmentTree
        build(0, 0, n-1, nums);    
    }
    
    void update(int index, int val) {
        updateTree(0, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return queryTree(0, 0, n - 1, left, right);
    }

    void build(int idx, int start, int end, vector<int> &nums){
        // base case
        if(start == end){ // means only 1 element left
            segmentTree[idx] = nums[start];
            return;
        }

        int mid = (start + end) / 2;  // can also do (start+end) >> 1 both are same
        // build left
        build(2*idx+1, start, mid, nums);

        // build right
        build(2*idx+2, mid+1, end,nums);

        segmentTree[idx] = segmentTree[2*idx+1] + segmentTree[2*idx+2]; 
    }

    void updateTree(int idx, int start, int end, int index, int val){
        // base case
        if(start == end){ // means we reached the element to update
            segmentTree[idx] = val;
            return;
        }

        int mid = (start + end) / 2;

        if(index <= mid){
            // left call
            updateTree(2*idx+1, start, mid, index, val);
        }
        else{
            // right call
            updateTree(2*idx+2, mid+1, end, index, val);
        }

        segmentTree[idx] = segmentTree[2*idx+1] + segmentTree[2*idx+2];
    }

    int queryTree(int idx, int start, int end, int left, int right){

        // Case 1. No overlap
        // [left right] [start end] [left right]

        if(right < start || end < left){
            return 0;
        }

        // Case 2. Complete Overlap
        // [left node-start node-end right]
        
        if(left <= start && end <= right){
            return segmentTree[idx];
        }

        int mid = (start + end) / 2;

        int leftCall = queryTree(2*idx+1, start, mid, left, right);
        int rightCall = queryTree(2*idx+2, mid+1, end, left, right);

        return (leftCall + rightCall);


    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */