//Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.


class Solution {
private:
    int isVovel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ){
            return 1;
        }
         return 0;
    }
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int ans = 0;
        int count = 0;
        for(int i=0;i<k;i++){
            if(isVovel(s[i])) count++;
        }

        ans = count;

        for(int i=k;i<n;i++){
            count = count - isVovel(s[i-k]) + isVovel(s[i]);
            ans = max(ans,count);
        }
        return ans;
    }
};