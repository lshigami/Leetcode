class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int k=nums.size()-1;k>=2;k--){
            int left=0;
            int right=k-1;
            while(left<right){
                if(nums[left]+nums[right]>nums[k]){
                    cnt+=right-left;
                    right-=1;
                }else left+=1;
            }
        }
        return cnt;
    }
};