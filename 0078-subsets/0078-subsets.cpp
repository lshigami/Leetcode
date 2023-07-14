class Solution {
public:
    vector<vector<int>> subsets(vector<int>& v) {
        int n=(int)pow(2,v.size());
        vector<vector<int>>vt;
        vector<int>temp;
        vt.push_back(temp);
        Try(v,temp,vt,n,0,0);
        return vt;
    }
    
    void Try(vector<int>s, vector<int>v , vector<vector<int>>&vt , int n, int cnt, int idx){
        for(int i=idx;i<s.size();i++){
            v.push_back(s[i]);
            cnt++;
            vt.push_back(v);
            if(cnt==n) return;
            Try(s,v,vt,n,cnt,i+1);
            v.pop_back();
        }
    }
};