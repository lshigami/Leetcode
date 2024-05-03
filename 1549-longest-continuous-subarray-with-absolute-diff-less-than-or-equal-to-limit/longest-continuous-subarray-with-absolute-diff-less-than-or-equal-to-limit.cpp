class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int>s;
        int left=0,ans=1;
        for(int right=0;right<nums.size();right++){
            s.insert(nums[right]);
            while(!s.empty() && *s.rbegin()-*s.begin() > limit){
                s.erase(s.find(nums[left++])) ;
            }
            ans=max(ans,right-left+1);
        }
     return ans;
    }
};