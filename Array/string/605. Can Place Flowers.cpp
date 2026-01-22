// You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

// Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        for(int i=0;i<size;i++){
            int left = i == 0 ? 0 : flowerbed[i-1];
            int right = i == size-1 ? 0 : flowerbed[i+1];
            if(left == 0 && right == 0 && flowerbed[i] == 0){
                 n--;
                 flowerbed[i] = 1;
            }
            if(n<=0) break;
        }
        return n<=0;
    }
};