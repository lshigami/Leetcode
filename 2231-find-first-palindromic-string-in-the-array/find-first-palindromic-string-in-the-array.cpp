class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto x:words){
            if(valid(x)) return x;
        }
        return "";
    }
    bool valid(string a){
        string s=a;
        reverse(a.begin(),a.end());
        return s==a;
    }
};