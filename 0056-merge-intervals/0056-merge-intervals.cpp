class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>> vt;
        sort(v.begin(), v.end());
        if (v.size() == 1) {
            return v;
        }
        vector<int> current = v[0];
        for (int i = 1; i < v.size(); i++) {
            if (current[1] < v[i][0]) {
                vt.push_back(current);
                current = v[i];
            } else {
                current[1] = max(current[1], v[i][1]);
            }
        }
        vt.push_back(current);
        return vt;
    }
};
