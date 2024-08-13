class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        int MOD=1e9+7;
        // prefix sum for later use
        vector<long long>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        //save index which value is smaller than nums[i]
        vector<int>leftMin(n,-1);
        vector<int>rightMin(n,n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]<=nums[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                leftMin[i]=st.top();
            }
            st.push(i);
        }
        //clear stack
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]<=nums[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                rightMin[i]=st.top();
            }
            st.push(i);
        }
        long long minProduct=INT_MIN;
        for(int i=0;i<n;i++){
            int left=leftMin[i]+1;
            int right=rightMin[i]-1;
            long long sum = prefix[right] - (left > 0 ? prefix[left - 1] : 0);
            long long value = nums[i] * sum;
            minProduct=max(minProduct,value);
        }
        return minProduct%MOD;
    }
};