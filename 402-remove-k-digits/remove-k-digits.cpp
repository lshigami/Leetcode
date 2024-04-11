class Solution {
public:
    string removeKdigits(string s, int k) {
        if(k==s.size()) return "0";
        stack<char>st;
        for(int i=0;i<s.size() ;i++){
            while(!st.empty() && s[i]<st.top() && k!=0 ){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        while(!st.empty() && k){
            k--;
            st.pop();
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        cout<<ans;
        for(int i=ans.size()-1;i>=1;i--){
            if(ans[i]=='0') ans.pop_back();
            else break;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};