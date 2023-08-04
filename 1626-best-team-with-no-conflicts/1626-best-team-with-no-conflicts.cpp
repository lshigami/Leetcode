class Solution {
public:
    int bestTeamScore(vector<int>& v, vector<int>& c) {
        int n=v.size();
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            vp.push_back({c[i],v[i]});
        }
        sort(vp.begin(),vp.end());
        vector<int>f(n);
        for(int i=0;i<n;i++){
            f[i]=vp[i].second;
            for(int j=0;j<i;j++){
                if((vp[i].first>=vp[j].first && vp[i].second>=vp[j].second) || (vp[i].first<=vp[j].first && vp[i].second<=vp[j].second)) f[i]=max(f[i],f[j]+vp[i].second);
            }
        }
      return *max_element(f.begin(),f.end());
    }
};
