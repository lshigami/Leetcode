class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        vector<int>prefix(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        //1 2 4 5 
        //1 3 7 12
        for(auto x:queries){
            auto it=lower_bound(prefix.begin(),prefix.end(),x);
            if(it==prefix.end() || *it!=x ) ans.push_back(it-prefix.begin());
            else ans.push_back(it-prefix.begin()+1);
        }
        return ans;
    }
};