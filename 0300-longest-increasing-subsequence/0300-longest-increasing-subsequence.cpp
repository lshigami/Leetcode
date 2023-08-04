class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n=v.size();
        vector<int>f(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
               if(v[i]>v[j])  f[i]=max(f[i],f[j]+1);
            }
        }
        return *max_element(f.begin(),f.end());
    }
};