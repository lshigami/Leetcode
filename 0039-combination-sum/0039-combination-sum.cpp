class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& v, int target) {
        vector<int>temp;
         vector<vector<int>>vt;
        Try(temp,v,vt,target,0,0);
        return vt;
    }
    
    void Try(vector<int>temp, vector<int>v,  vector<vector<int>>&vt, int k, int sum, int idx){
    for(int i=idx;i<v.size();i++){
        sum+=v[i];
        temp.push_back(v[i]);
        if(sum==k){
            vt.push_back(temp);
        }
        else if(sum<k){
            Try(temp,v,vt,k,sum,i);
        }
        sum-=v[i];
        temp.pop_back();
    }
}
};