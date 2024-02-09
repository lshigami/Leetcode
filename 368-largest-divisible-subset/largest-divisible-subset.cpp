class Solution {
public:
    vector<int> dp, succ, ans;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
		// initially dp[i]=1 since we can always form subset of size=1 starting at i. 
		// succ[i]= ∞  because we havent found any successors for any subset yet
        dp.resize(size(nums), 1), succ.resize(size(nums), INT_MAX);
        for(int i = 0; i < size(nums); i++)  solve(nums, i);
		// reconstruct starting from index where largest subset starts till the end. succ[i] gives next element after each index
        for(int i = distance(begin(dp), max_element(begin(dp), end(dp))); i < size(nums); i = succ[i]) 
            ans.push_back(nums[i]);
        return ans;
    }
    int solve(vector<int>& nums, int start) {
        if(start >= size(nums)) return 0;
        if(dp[start] != 1) return dp[start];   // initially all dp[i]=1. But if it's updated to store largest subset size, just return it.
        for(int next = start+1; next < size(nums); next++) {
            if(nums[next] % nums[start]) continue;
            int size = solve(nums, next);
            if(dp[start] < size + 1) {   // if choosing subset start at nums[next] gives bigger subset at start, choose it
                dp[start] = size + 1;    // update dp[i] to store size of largest subset
                succ[start] = next;      // next element at dp[i] which yields largest subset
            }
        }
        return dp[start];
    }
};