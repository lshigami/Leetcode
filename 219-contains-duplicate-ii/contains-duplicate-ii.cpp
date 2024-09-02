class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int left=0;
        map<int,int>m;
        for(int right=0;right<nums.size();right+=1){
            if(right>k){
                m[nums[left++]]-=1;
            }
            m[nums[right]]+=1;
            if(m[nums[right]]>1) return true;
        }
        return false;
    }
};