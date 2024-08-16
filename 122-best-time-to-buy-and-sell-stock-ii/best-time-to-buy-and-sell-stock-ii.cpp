class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=0;i<prices.size()-1;i+=1){
            if(prices[i+1]>prices[i]) profit+=prices[i+1]-prices[i];
        }
        return profit;
    }
};