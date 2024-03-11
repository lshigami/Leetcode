class Solution {
public:
    struct cmp {
        bool operator()(pair<int,int> a, pair<int,int>b){
            return a.second < b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(auto x:nums){
            m[x]++;
        }
        vector<int>ans;
        priority_queue< pair<int,int>,vector<pair<int,int>>,cmp >pq;
        for(auto x:m){
            pq.push({x.first,x.second});
        }
        for(int i=1;i<=k;i++){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
