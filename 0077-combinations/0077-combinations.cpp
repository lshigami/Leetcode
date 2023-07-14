class Solution {
public:
    int combination(int n, int k) {
        if (k == 0 || k == n) {
            return 1;
        } else {
            return combination(n - 1, k - 1) + combination(n - 1, k);
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int>v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        vector<vector<int>>vt;
        vector<int>temp;
        Try(vt,v,temp,combination(n,k),k,0,0);
        return vt;
    }
    
    void Try(vector<vector<int>>&vt, vector<int>v, vector<int>temp, int n, int k, int idx, int cnt){
        for(int i=idx;i<v.size();i++){
            temp.push_back(v[i]);
            if(temp.size()==k){
                vt.push_back(temp);
              //  cnt++;
             //   if(cnt==n) return;
            }
            else Try(vt,v,temp,n,k,i+1,cnt);
            temp.pop_back();
        }
    }
    
};