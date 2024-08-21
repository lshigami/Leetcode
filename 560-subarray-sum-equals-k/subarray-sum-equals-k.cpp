class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>prefix(nums.size());
        unordered_map<int,int>m;
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i];
            
        }
        int cnt=0;
        for(int i=0;i<nums.size();i+=1){
            if(m.find(prefix[i]-k)!=m.end()) cnt+=m[prefix[i]-k];
            m[prefix[i]]+=1;
        }
        cnt+=m[k];
        return cnt;
        //1 2 3
        //1 3 6
        //pre[j]-pre[i]=k
        //-1 -2 -1

        //1 0 0
        

    }
};