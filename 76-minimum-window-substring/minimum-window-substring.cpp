class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for (auto c : t)
            m[c]++;

        int count = 0;
        int low = 0;
        int min_length = INT_MAX, min_start = 0;

        for (int high = 0; high < s.length(); high++) {
            if (m[s[high]] > 0)
                count++;
            m[s[high]]--;
            if (count == t.length()) {
                while (low < high && m[s[low]] < 0) {
                    m[s[low]]++;
                    low++;
                }
                if (min_length > (high - low + 1)) {
                    min_length = high - low + 1;
                    min_start = low;
                }
            }
        }
        return (min_length == INT_MAX) ? "" : s.substr(min_start, min_length);
    }
};