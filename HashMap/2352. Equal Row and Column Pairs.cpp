// Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.


class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans=0;
        map<vector<int>, int> mp1, mp2;
        for(int i=0; i<grid.size(); i++){
            mp1[grid[i]]++;
            vector<int> col;
            for(int j=0; j<grid.size(); j++) col.push_back(grid[j][i]);
            mp2[col]++;
        }
        for(auto m: mp1) if(mp2.find(m.first) != mp2.end()) ans+=m.second * mp2[m.first];
        return ans;
    }
};
