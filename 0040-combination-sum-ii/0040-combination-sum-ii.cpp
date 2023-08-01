class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>&v, int target) {
        sort(v.begin(),v.end());
        vector<int>temp;
        set<vector<int>>s;
                Try(s,v,temp,0,0,target);

        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
    void Try(set<vector<int>>&s,vector<int>v,vector<int>temp,int sum,int idx,int target){
        for(int i=idx;i<v.size();i++){
           if(i > idx && v[i] == v[i-1]) continue; // skip over duplicates
            sum+=v[i];
            temp.push_back(v[i]);
            if(sum==target) s.insert(temp);
            else if(sum<target) Try(s,v,temp,sum,i+1,target);
            sum-=v[i];
            temp.pop_back();
        }
    }
};