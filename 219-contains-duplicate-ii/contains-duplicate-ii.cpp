class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>m;
        for(int i=0;i<=min(k,(int)nums.size()-1);i++){
            if(m[nums[i]]==0) m[nums[i]]=1;
            else return true;
        }
        int left=0;
        
        for(int i=k+1;i<nums.size();i++){
            m[nums[left]]=0;
            left+=1;
            if(m[nums[i]]) return true;
            else m[nums[i]]=1;
        }
        return false;
    }
};