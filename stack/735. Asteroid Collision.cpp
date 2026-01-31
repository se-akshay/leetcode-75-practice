class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n = asteroids.size();
        for(int i=0;i<n;i++){
            if(asteroids[i] < 0){
                while(ans.size()!=0 && ans.back() > 0 && ans.back()<abs(asteroids[i])){
                    ans.pop_back();
                }
                if(ans.size() != 0 && ans.back() == abs(asteroids[i])){
                    ans.pop_back();
                }else if(ans.size() == 0 || ans.back() < 0){
                    ans.push_back(asteroids[i]);
                }
            }else{
                ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
};