class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minLeft(n);
        vector<int> minRight(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] <= nums[st.top()]) st.pop();
            if (st.empty()) minLeft[i] = -1;
            else minLeft[i] = st.top();
            st.push(i);
        }
        
        while (!st.empty()) st.pop();
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] <= nums[st.top()]) st.pop();
            if (st.empty()) minRight[i] = n;
            else minRight[i] = st.top();
            st.push(i);
        }
        
        int maxScore = 0;
        for (int i = 0; i < n; i++) {
            int left = minLeft[i] + 1; 
            int right = minRight[i] - 1; 
            if (left <= k && k <= right) {
                maxScore = max(maxScore, nums[i] * (right - left + 1));
            }
        }
        
        return maxScore;
    }
};
