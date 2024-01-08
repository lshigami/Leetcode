class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(auto x:s){
            if(x=='*') st.pop();
            else st.push(x);
        }
        string ans="";
        while(!st.empty()){
            char c=st.top();
            ans+=string(1,c);
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};