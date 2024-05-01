class Solution {
public:
    string reversePrefix(string word, char ch) {
        int left=0;
        int right=word.find(ch);
        while(left<right) swap(word[left++],word[right--]);
        return word;
    }
};