class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& v) {
        vector<int>ans(v.size());
        stack<int>st;
        for(int i=v.size()-1;i>=0;i--){
            while(!st.empty() && v[i]>st.top()){
                st.pop();
                ans[i]+=1;
           } 
            if(!st.empty()) ans[i]+=1;
            st.push(v[i]);
        }
        return ans;
    }
};