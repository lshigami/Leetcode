class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto x : nums) {
            m[x]++;
        }
        vector<int> ans;
        vector<pair<int,int>>vp;
        for(auto x:m){
            vp.push_back({x.first,x.second});
        }
        sort(vp.begin(),vp.end(),[](pair<int,int>a,pair<int,int>b)->bool{
            return a.second>b.second;
        });
        for(int i=0;i<k;i++){
            ans.push_back(vp[i].first);
        }
        return ans;
    }
};