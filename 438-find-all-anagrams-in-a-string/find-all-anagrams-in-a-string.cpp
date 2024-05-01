class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> m;
        for (char c : p) m[c]++;

        vector<int> ans;
        unordered_map<char, int> temp;
        int left = 0, right = 0, count = m.size();

        while (right < s.size()) {
            if (m.count(s[right])) {
                temp[s[right]]++;
                if (temp[s[right]] == m[s[right]]) count--;
            }
            right++;

            while (count == 0) {
                if (right - left == p.size()) ans.push_back(left);
                if (m.count(s[left])) {
                    temp[s[left]]--;
                    if (temp[s[left]] < m[s[left]]) count++;
                }
                left++;
            }
        }
        return ans;
    }
};
