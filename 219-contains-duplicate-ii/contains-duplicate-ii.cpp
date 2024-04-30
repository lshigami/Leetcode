class Solution {
public:
/*
    abs(i-j)<=k
(=) size of window max =k 


*/

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>m;
        int n=nums.size();
        if(k==n) k-=1;
        for(int i=0;i<=min(k,n-1);i++){
            if(m.find(nums[i])==m.end()) m[nums[i]]=1;
            else {
                 cout<<i;
                return true;
            }
        }
        int left=0;
        for(int i=k+1;i<n;i++){
            m[nums[left++]]=0;
            if(m[nums[i]]) {
                cout<<i;
                return true;
            }
            else m[nums[i]]=1;
        }
        return false;
    }
};