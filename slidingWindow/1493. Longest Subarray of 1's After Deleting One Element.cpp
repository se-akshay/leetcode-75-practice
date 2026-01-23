// Given a binary array nums, you should delete one element from it.
// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

// Method :: Bruteforce TC: O(n^2) SC: O(1)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int  n = nums.size();
       int ans = 0;
       for(int i=0;i<n;i++){
        int count = 0;
        for(int j = i;j<n;j++){
            if(nums[j] == 0) count ++;
            if(count <= 1){
                ans = max(ans,j-i);
            }else {
                break;
            }
        }
       } 
        return ans;
    }
};


// Method :: optimal double pointer TC: O(2n) SC: O(1)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0;
        int count = 0;
        int ans = 0;
        while(r < n){
            if(nums[r] == 0) count ++;
            while(count > 1){
                if(nums[l] == 0) count--;
                l++;
            }
            ans = max(ans,r-l);
            r++;
        }
        return ans;
    }
};