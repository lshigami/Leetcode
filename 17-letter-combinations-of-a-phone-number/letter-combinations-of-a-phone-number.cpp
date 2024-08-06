class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string phone[10];
        phone[2] = "abc";
        phone[3] = "def";
        phone[4] = "ghi";
        phone[5] = "jkl";
        phone[6] = "mno";
        phone[7] = "pqrs";
        phone[8] = "tuv";
        phone[9] = "wxyz";

        vector<string> res;
        string cur = "";
        type(0, digits, phone, cur, res);
        return res;
    }

    void type(int index, const string& digits, const string phone[10], string cur, vector<string>& res) {
        int phoneIndex = digits[index] - '0';
        for (char c : phone[phoneIndex]) {
            cur.push_back(c);
            if(cur.size()==digits.size()){
                res.push_back(cur);
            }
            else{
                type(index + 1, digits, phone, cur, res);
            }
            cur.pop_back(); 
        }
    }
};
