class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r && s[l] == s[r]) {
            char c = s[l];
            while (l <= r && s[l] == c)
                l++;
            while (l <= r && s[r] == c)
                r--;
        }
        return r - l + 1;
    }
};