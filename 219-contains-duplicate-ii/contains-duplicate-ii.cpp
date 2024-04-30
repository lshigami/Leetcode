class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,bool>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>k) m[nums[i-k-1]]=0;
            if(m[nums[i]]) return true;
            m[nums[i]]=1;
        }
        return false;
    }
};