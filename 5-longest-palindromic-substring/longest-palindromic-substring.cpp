class Solution {
public:
    string str;
    vector<int> rad;
    int ans = 0;
    string out;
    void init(string &s) {
        str = string((int)s.length() * 2 + 2, ' ');
        str[0] = str[1] = '#';
        for (int i = 0; i < s.length(); ++i) {
            str[i * 2 + 2] = s[i];
            str[i * 2 + 3] = '#';
        }
    }
    
    void manacher(string &s) {
        rad = vector<int> ((int)str.length(), 0);
        int mr = 0, mid;
        for (int i = 1; i < str.length(); ++i) {
            rad[i] = i < mr ? min(mr - i, rad[mid * 2 - i]) : 1;
            for (; str[i + rad[i]] == str[i - rad[i]]; ++rad[i]) 
                if (i + rad[i] > mr) 
                    mid = i, mr = i + rad[i];
            if (rad[i] - 1 > ans) {
                ans = rad[i] - 1; 
                out = s.substr((i - ans) / 2, ans); 
            }
        }
    }
    
    string longestPalindrome(string s) {
        init(s);
        manacher(s);
        return out;
    }
};