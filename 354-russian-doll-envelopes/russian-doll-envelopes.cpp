class Solution {
public:
    int lowerBound(const vector<vector<int>>& envs, const vector<int>& value) {
        int left = 0;
        int right = envs.size() - 1;
        int ans=envs.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (envs[mid][1] >= value[1]) {
                ans=mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0] < b[0]) || (a[0] == b[0] && a[1] > b[1]);
        });

        vector<vector<int>> res;
        for(auto x:envelopes){
            cout<<x[0]<<" "<<x[1]<<endl;
        }
        for (const auto& env : envelopes) {
            int index = lowerBound(res, env);
            if (index == res.size()) {
                res.push_back(env);
            } else {
                res[index] = env;
            }
        }
        return res.size();
    }
};