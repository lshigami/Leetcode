class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        for(auto digit:num){
            while(!st.empty() && k && st.top()>digit){
                st.pop();
                k-=1;
            }
            st.push(digit);
        }
        while(k && !st.empty()){
            st.pop();
            k-=1;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        auto pos=ans.find_first_not_of('0');
        ans= pos==string::npos ? "0":ans.substr(pos);
        return ans.empty() ? "0" : ans;
    }
};