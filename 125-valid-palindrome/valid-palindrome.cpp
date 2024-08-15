class Solution {
public:
    bool isPalindrome(string s) {
        string pan="";
        for(auto x:s){
            if(isalpha(x)) pan+=tolower(x);
            if(isdigit(x)) pan+=x;
        }
        string rev=pan;
        reverse(pan.begin(),pan.end());
        return rev==pan;
    }
};