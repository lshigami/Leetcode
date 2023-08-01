class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        vector<vector<int>>vt;
        vector<int>temp;
        vt.push_back(temp);    
        Try(vt,v,temp,0);
        set<vector<int>>s;
        for(auto &x:vt) {
            sort(x.begin(),x.end());
            s.insert(x);
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
    void Try(vector<vector<int>>&vt,vector<int>v,vector<int>temp,int idx){
        for(int i=idx;i<v.size();i++){
            temp.push_back(v[i]);
            vt.push_back(temp);
            Try(vt,v,temp,i+1);
            temp.pop_back();
        }
    }
};