class Solution {
public:
    int binarySearch(vector<int>&nums,int x){
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int m=(left+right)/2;
            if(nums[m]==x) return m;
            else if(nums[m]>x) right=m-1;
            else left=m+1;
        }
        return -1;
    }
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<1000;i++){
            auto it=lower_bound(nums.begin(),nums.end(),i);
            if(it==nums.end()) continue;
            int idx=(it-nums.begin());
            if(i==nums.size()-idx) return i;
        }
        return -1;
    }
    
};
//0 0 3 4 4  s=5
//0 1 2 3 4  idx=2