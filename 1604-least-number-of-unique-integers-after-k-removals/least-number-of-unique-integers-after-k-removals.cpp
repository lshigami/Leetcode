class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>m;
        for(auto x:arr){
            m[x]++;
        }
        sort(arr.begin(),arr.end(),[&m](int a,int b)->bool{
            return m[a]<m[b];
        });
        // 1 1 3 3 3 4 4 4 5 5 5 : 4
        int ans=0;
        for(auto x:arr){
            if(k>0) {
                k-=m[x];
                if(k>=0) m[x]=0;
                else m[x]-=k;
            }
        }
        for(auto x:m){
            if(x.second>0) ans++;
        }
        return ans;
    }
};