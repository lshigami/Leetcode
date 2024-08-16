class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int>st;
        vector<int>right(prices.size(),-1);
        for(int i=prices.size()-1;i>=0;i--){
            while(!st.empty() && prices[i]>=prices[st.top()]) st.pop();
            if(!st.empty()) right[i]=st.top();
            st.push(i);
        }
        int profit=0;
        for(auto x:right) cout<<x<<" ";
        for(int i=0;i<prices.size();i++){
            if (right[i] != -1) {
                int indexGreater=right[i];
                while(right[indexGreater]!=-1){
                    right[i]=right[indexGreater];
                    indexGreater=right[indexGreater];
                }
                profit=max(profit,prices[right[i]] - prices[i]);
            }
        }
        return profit;
    }
};