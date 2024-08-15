class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>a,vector<int>b){
            return a[0]<b[0] || a[0]==b[0] && a[1]<b[1];
        });
        stack<vector<int>>st;
        vector<vector<int>>res;
        for(auto x:intervals){
            if(!st.empty() && st.top()[1]>=x[0]){
                st.top()[1]=max(st.top()[1],x[1]);
            }
            else st.push(x);
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};