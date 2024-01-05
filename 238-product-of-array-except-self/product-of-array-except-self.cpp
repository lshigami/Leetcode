class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        int n=v.size();
        vector<int>prefi(n,1);
        vector<int>prela(n,1);
        for(int i=1;i<n;i++){
            prefi[i]=prefi[i-1]*v[i-1];
            prela[i]=prela[i-1]*v[n-i];
        }
        vector<int>ans(n,1);
        for(int i=0;i<n;i++){
            ans[i]=prefi[i]*prela[n-i-1];
        }
        return ans;
    }
};