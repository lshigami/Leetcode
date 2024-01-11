class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> temp(temperatures.size(), 0);
        stack<pair<int, int>> st;
        
        st.push({0, temperatures[0]});
        
        for(int i=1; i<temperatures.size(); i++){
            pair<int, int> now = st.top();
            
            while(!st.empty() && temperatures[i] > now.second){
                temp[now.first] = i - now.first; 
                st.pop();
                
                if(!st.empty()) {
                    now = st.top();
                }
            }
            
            st.push({i, temperatures[i]});
        }
        
        return temp;
    }
};