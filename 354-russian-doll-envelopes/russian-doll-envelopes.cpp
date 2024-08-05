class Solution {
public:
    int lowerBound(const vector<vector<int>>& envs, vector<int> value) {
        int index = envs.size();
        int left = 0;
        int right = envs.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (envs[mid][1] >= value[1]) {
                index = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return index;
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sắp xếp theo chiều rộng tăng dần và chiều cao giảm dần nếu chiều rộng bằng nhau
        sort(envelopes.begin(), envelopes.end(), [](vector<int> a, vector<int> b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        
        vector<vector<int>> res;
        res.push_back(envelopes[0]);
        for (int i = 1; i < envelopes.size(); i++) {
            int index = lowerBound(res, envelopes[i]);
            if (index == res.size()) {
                res.push_back(envelopes[i]);
            } else {
                res[index] = envelopes[i];
            }
        }
        return res.size();
    }
};
