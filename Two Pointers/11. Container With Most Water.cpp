// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).


class Solution {
public:
    static inline int area(int l, int r, vector<int>& height){
        return min(height[l], height[r])*(r-l);
    }
    static int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0, r=n-1;
        int A=0;
        while (l<r){
            A=max(A, area(l, r, height));
            if(height[r]<height[l]) r--;
            else l++;
        }
        return A;   
    }
};
