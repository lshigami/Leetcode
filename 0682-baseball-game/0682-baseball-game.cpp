class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(auto x:operations){
            if(x=="C") st.pop();
            else if(x=="D") {
                int a=st.top();
                a*=2;
                st.push(a);
            }
            else if(x=="+"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.push(a);
                st.push((a+b));
            }
            else st.push(stoi(x));
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};