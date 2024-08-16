class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int MIN=prices[0];
        int MAX=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
            MIN=min(MIN,prices[i]);
            profit=max(profit,prices[i]-MIN);
        }
        return profit;
    }
};