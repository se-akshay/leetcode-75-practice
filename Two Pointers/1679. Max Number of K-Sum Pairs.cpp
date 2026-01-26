// You are given an integer array nums and an integer k.

// In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

// Return the maximum number of operations you can perform on the array.


class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0, r = n-1;
        int count = 0;
        while(l<r){
            if(nums[l]+nums[r] > k){
                r--;
            }else if(nums[l]+nums[r] < k){
                l++;
            }else{
                count++;
                l++;
                r--;
            }
        }
        return count;
    }
};