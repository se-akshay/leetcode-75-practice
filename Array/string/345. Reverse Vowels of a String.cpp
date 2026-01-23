// Given a string s, reverse only all the vowels in the string and return it.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.



class Solution {
private:
    bool is_vowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    } 
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size();
        while(l<r){
            while(l<r && !is_vowel(s[r]))r--;
            while(l<r && !is_vowel(s[l]))l++;
            swap(s[l],s[r]);
            l++;
            r--;
        }
        return s;
    }
};