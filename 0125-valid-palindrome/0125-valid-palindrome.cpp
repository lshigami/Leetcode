class Solution {
public:
    bool isPalindrome(string s) {
        int l=0;
        int r=s.size()-1;
        if(s.size()==1) return true;
        while(l<=r){
            while(l<s.size() &&!isalpha(s[l]) &&!isdigit(s[l])) l++;
            while(r<s.size() &&!isalpha(s[r]) &&!isdigit(s[r])) r--;
            if(r<s.size()&& l<s.size()&& tolower(s[r])!=tolower(s[l])) return false;
            else {
                l++; 
                r--;
            }
        }
        return true;
    }
};