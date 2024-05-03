class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        vector<int>res(2*n,-1);
        stack<int>st;
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
            if(!st.empty()) res[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<2*n-1;i++) {
            if(res[i]!=-1) res[i]=nums[res[i]%n];
        }
        res.erase(res.begin()+n,res.end());
        return res;
    }
};