// Method:: bruteforce TC: O(n^2) || SC: O(1)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            // sum of left
            int leftSum = 0;
            for(int j = 0; j<i;j++){
                leftSum += nums[j];
            }

            // sum of right
            int rightSum = 0;
            for(int j = i+1;j<n;j++){
                rightSum += nums[j];
            }

            if(leftSum == rightSum) return i;
        }
        return -1;
    }
};


// Method :: optimal TC: O(2n) | SC: O(1)

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }
        int rightSum = 0;
        int pivot = -1;
        for(int i = n-1;i>=0;i--){
            if(rightSum == totalSum - nums[i]) pivot = i;
            rightSum += nums[i];
            totalSum -= nums[i];
        }
        return pivot;
    }
};