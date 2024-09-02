class Solution {
public:
    bool isAnagram(string s, string t) {
        return multiset(s.begin(),s.end())==multiset(t.begin(),t.end());
    }
};