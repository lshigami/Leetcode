class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        map<int,int>m;
        int n=nums.size();
        for(int j=(n*2-1);j>=0;j--){
            int i=j%n;
            while(!st.empty() && nums[i]>=st.top()){
                st.pop();
            }
            if(st.empty()) m[i]=-1;
            else{
                m[i]=st.top();
            }
            st.push(nums[i]);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(m[i]);
        }  
        return ans;
    }
};