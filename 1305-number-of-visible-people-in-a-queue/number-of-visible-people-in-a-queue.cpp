class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& v) {
        unordered_map<int, int> m;
        for (int i = 0; i < v.size(); i++) m[i] = 0;
        stack<int> st;
        for (int i = 0; i < v.size(); i++) {
            if (st.empty()) st.push(i);
            else {
                if (v[i] > v[st.top()]) {
                    while (!st.empty() && v[i] > v[st.top()]) {
                        m[st.top()] += 1;
                        st.pop();
                    }
                }
                if (!st.empty()) {
                    m[st.top()] += 1;
                    st.push(i);
                }else st.push(i);
            }
        }
        vector<int> ans(v.size());
        for (auto x : m) {
            ans[x.first] = x.second;
        }
        return ans;
    }
};