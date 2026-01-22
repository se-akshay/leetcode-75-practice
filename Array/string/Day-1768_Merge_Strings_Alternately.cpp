//You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.Return the merged string.


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i1,i2;
        int n1,n2;
        i1 = i2 = 0;
        n1 = word1.size(), n2 = word2.size();
        string combined = "";
        while(i1<n1 && i2<n2){
                combined += word1[i1++];
                combined += word2[i2++];
        }
        if(i1<n1){
            combined += word1.substr(i1);
        }
        if(i2<n2){
            combined += word2.substr(i2);
        }
        return combined;
    }
};

// Approach: Two pointers
// Time Complexity: O(n)
// Space Complexity: O(n)