class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int countZero=0;
        int MAX=0;
        int left=0;
        const int limit=k;
        for(int right=0;right<nums.size();right+=1){
            if(nums[right]==0) countZero+=1;
            while(countZero>limit){
                if(nums[left]==0) countZero-=1;
                left+=1;
            }
            MAX=max(MAX,right-left+1);
        }
        return MAX;
    }
};