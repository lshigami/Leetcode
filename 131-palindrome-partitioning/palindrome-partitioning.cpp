class Solution {
public:
    bool isPanlidrome(string s) {
        string temp = s;
        reverse(temp.begin(), temp.end());
        return temp == s;
    }

    void Backtrack(vector<vector<string>>& ans, vector<string> temp, string s,int start, int n) {
        for (int i = start; i < n; i++) {
            if (isPanlidrome(s.substr(start, i - start + 1))) {
                temp.push_back(s.substr(start, i - start + 1));
                if (i != n-1) Backtrack(ans, temp, s, i + 1, n);
                else ans.push_back(temp);
                temp.pop_back();
            }
        }   
    }   

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        Backtrack(ans, temp, s, 0, s.size());
        return ans;
    }
};