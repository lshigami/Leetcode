class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s = "()";
        vector<string> v;
        Try(s, v, "", n);
        return v;
    }
    
    bool check(string s) {
        int sum = 0;
        for (auto x : s) {
            if (x == '(') sum += 1;
            else sum -= 1;
            if (sum < 0) return false;
        }
        return sum == 0;
    }

    void Try(string s, vector<string>& v, string temp, int n) {
        for (int i = 0; i <= 1; i++) {
            temp += s[i];
            if (temp.size() == 2 * n) {
                if (check(temp)) v.push_back(temp);
            }
            else Try(s, v, temp, n);
            temp.pop_back();
        }
    }
};
