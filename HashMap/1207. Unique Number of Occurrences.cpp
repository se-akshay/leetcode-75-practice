// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        unordered_set<int> s;
        int c=0;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }

        for(auto x: m){
            s.insert(x.second);
            c++;
        }

        if(c==s.size()){
            return true;
        }else{
            return false;
        }
    }
};