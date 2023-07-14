class Solution {
public:
    vector<vector<int>> permute(vector<int>& v) {
        vector<vector<int>>vt;
        vector<int>temp;
        map<int,bool>m;
        for(int i=0;i<v.size();i++){
            m[i]=false;
        }
        Try(vt,v,temp,m);
        return vt;
    }
    void Try( vector<vector<int>>&vt, vector<int>v, vector<int>temp,  map<int,bool>&m){
        for(int i=0;i<v.size();i++){
            if(m[v[i]]==false){
                temp.push_back(v[i]);
                m[v[i]]=true;
                if(temp.size()==v.size()){
                    vt.push_back(temp);
                }
                else Try(vt,v,temp,m);
                m[v[i]]=false;
                temp.pop_back();
            }
        }
    }
};