// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.


class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string temp = "";

        // remove extra spaces
        for(int i=0;i<n;i++){
            if(s[i] == ' ' && (temp.empty() || temp.back() == ' ')){
                continue;
            }else{
                temp += s[i];
            }
        }

        // remove trailing space 
        if(!temp.empty() && temp.back() == ' ') temp.pop_back();

        // reverse entire string
        reverse(temp.begin(),temp.end());

        // reverse each words in the string
        int start = 0;
        n = temp.size();
        for(int i=0;i<=n;i++){
            if(i == n || temp[i] == ' '){
                reverse(temp.begin()+start,temp.begin()+i);
                start = i+1;
            }
        }
        return temp;
    }
};