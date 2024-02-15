class Solution {
public:
    long long largestPerimeter(vector<int>& v) {
        sort(v.begin(), v.end());
        long long ans = -1;
        long long sum = 0;
        for (int i = 0; i < v.size(); i++) {
            if (i >= 2 && sum > v[i])
                ans = sum + v[i];
            sum += v[i];
        }
        return ans;
    }
};