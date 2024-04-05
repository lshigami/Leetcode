class Solution {
public:
    bool badString(char a,char b){
        return (islower(a) && isupper(b) && tolower(a)==tolower(b)) or (isupper(a) && islower(b) and tolower(a)==tolower(b));
    }
    string makeGood(string s) {
        stack<char>st;
        st.push(s[0]);
        int i=1;
        while(i<s.size()){
            if( !st.empty() && badString(st.top(),s[i])) {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
            i++;

        }
        string ans="";
        while(!st.empty()){
            ans+=string(1,st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};