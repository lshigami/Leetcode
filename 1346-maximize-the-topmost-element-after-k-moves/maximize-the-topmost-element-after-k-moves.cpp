class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k==0) return nums[0];
        if(k==1){
            if(nums.size()==1) return -1;
            else return nums[1];
        }
        if(nums.size()==1){
            if(k%2!=0) return -1;
            else return nums[0];
        }
        int MAX=-1;
        // use k-1 operation for remove and 1 operation for push
        vector<int>removed;
        for(int i=0;i<min(k-1,(int)nums.size());i++){
            removed.push_back(nums[i]);
        }
        sort(removed.begin(),removed.end());
        MAX=max( removed[removed.size()-1],MAX);
        // use k operation for remove <but make that n>k>
        if(nums.size()>k){
            MAX=max(MAX,nums[k]);
        }
        return MAX;
    }
};