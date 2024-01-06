class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>pre(nums.size());
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i]=nums[i]+pre[i-1];
        }
        for(int i=0;i<pre.size();i++){
             if(i==0){
                if(pre[pre.size()-1]-pre[i]==0) return 0;
                continue;
            }
            if(pre[i-1]==pre[pre.size()-1]-pre[i]) return i;
        }
        return -1;
    }
};