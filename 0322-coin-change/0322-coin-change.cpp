class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> s(amount + 1, amount + 1);
        s[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i >= coins[j]) {
                    s[i] = min(s[i - coins[j]] + 1, s[i]);
                }
            }
        }
        return s[amount] > amount ? -1 : s[amount];
    }
};
