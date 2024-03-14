class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& v) {
        unordered_map<int,int>m;
        stack<int>st;
        for(int i=v.size()-1;i>=0;i--){
            while(!st.empty() && v[st.top()]<=v[i] ) st.pop();
            if(!st.empty()) m[v[i]]=v[st.top()]; else m[v[i]]=-1;
            st.push(i);
        }
        for(auto &x:nums1){
            x=m[x];
        }
        return nums1;
    }
};