// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.


// HINT :: try to find maximum subarray with at most Zeros = k.
 
// BruteForce ---> TC: O(n^2), SC O(1)


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), maxLen = 0;

        for (int i = 0; i < n; i++) {
            int zeros = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == 0) zeros++;

                if (zeros <= k) {
                    maxLen = max(maxLen, j - i + 1);
                } else {
                    break; 
                }
            }
        }
        return maxLen;
    }
};


// Better----> TC: ~O(2n), SC: O(1)
// Approach : Two pointer

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), maxLen = 0, zeros = 0, l = 0, r = 0;
        while(r<n){
            if(nums[r] == 0) zeros ++;

            while(zeros > k){
                if(nums[l] == 0) zeros --;
                l++;
            }
            if(zeros <= k) maxLen = max(maxLen,r-l+1);
            r++;
        }
        return maxLen;

    }
};
