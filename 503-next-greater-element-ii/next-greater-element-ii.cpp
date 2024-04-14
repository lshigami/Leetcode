class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        unordered_map<int,int>m;
        vector<int>ve(v.begin(),v.end());
        for(auto x:v){
            ve.push_back(x);
        }
        vector<int>ans(v.size());
        stack<int>st;
        for(int i=ve.size()-1;i>=0;i--){
            while(!st.empty() && ve[st.top()]<=ve[i]) st.pop();
            if(st.empty()) m[i]=-1; else m[i]=st.top();
            st.push(i);
        }
        for(auto x:m) cout<<x.first<<" "<<x.second<<endl;
        for(int i=0;i<v.size();i++){
            if(m[i]!=-1) ans[i]=v[m[i]%v.size()];
            else ans[i]=-1;
        }
        return ans;
    }
};