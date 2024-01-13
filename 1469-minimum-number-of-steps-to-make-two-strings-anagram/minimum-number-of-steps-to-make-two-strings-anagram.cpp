class Solution {
public:
    int minSteps(string s, string t) {
      vector<int> c(26);
      int m = 0;
      for (auto x : s) c[x - 'a']++;
      for (auto x : t) { c[x - 'a']--; if (c[x - 'a'] < 0) m++; }
      return m;
    }
};