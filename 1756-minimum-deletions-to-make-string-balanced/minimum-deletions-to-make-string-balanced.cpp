class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int cost=0;
        for(auto x:s){
            if(x=='b') st.push(x);
            else {
               
                if(st.empty()) continue;
                cost+=1;
                st.pop();
            }
        }
        return cost;
    }
};