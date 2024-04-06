class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char>prts;
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]!=')' && s[i]!='(') st.push(s[i]);
            else if(s[i]=='('){
                st.push('(');
                prts.push('(');
            }
            else{
                if(!prts.empty()) {
                    prts.pop();
                    st.push(')');
                }
                else{
                    continue;
                }
            }
        }
        string ans="";
        while(!st.empty()){
             if(st.top()=='(' && !prts.empty()){
                st.pop();
                prts.pop();
            }
            else{
                 ans+=st.top();
            st.pop();
            }
           
          
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//    (()
//    ()(