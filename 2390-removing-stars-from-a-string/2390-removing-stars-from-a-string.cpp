class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(auto x:s){
            if(isalpha(x)){
                st.push(x);
            }
            else {
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        string temp="";
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};
