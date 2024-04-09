
class Solution {
    unordered_map<int, std::vector<int>> memo;

public:
    vector<int> beautifulArray(int N) {
        memo.clear();
        return f(N);
    }
    vector<int> f(int N) {
        if (memo.find(N) != memo.end())
            return memo[N];
        vector<int> ans(N);
        if (N == 1) {
            ans[0] = 1;
        } else {
            int t = 0;
            for (int x : f((N + 1) / 2)) // odds
                ans[t++] = 2 * x - 1;
            for (int x : f(N / 2))       // evens
                ans[t++] = 2 * x;
        }
        memo[N] = ans;
        return ans;
    }
};
