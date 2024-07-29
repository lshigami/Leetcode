class Solution {
public:
    bool isGreater(const vector<int>& m1, const vector<int>& m2) {
        for (int i = 0; i < 128; ++i) {
            if (m2[i] > 0 && m1[i] < m2[i])
                return false;
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        vector<int> m1(128, 0), m2(128, 0);
        int minStart = 0, minLen = INT_MAX;
        int left = 0;
        
        for (char x : t) {
            m2[x] += 1;
        }
        
        for (int right = 0; right < s.size(); ++right) {
            m1[s[right]] += 1;
            while (isGreater(m1, m2)) {
                int newStringSize = right - left + 1;
                if (newStringSize < minLen) {
                    minStart = left;
                    minLen = newStringSize;
                }
                
                m1[s[left]] -= 1;
                left += 1;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};