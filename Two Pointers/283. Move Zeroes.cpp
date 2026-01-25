// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n =  nums.size();
        int lastNonZero = 0;
        for(int i=0;i<n;i++){
            if(nums[i] != 0){
                swap(nums[i],nums[lastNonZero++]);
            }
        }
        return;
    }
};