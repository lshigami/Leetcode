class Solution {
public:
    int maxOperations(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        int l=0;
        int r=v.size()-1;
        int ans=0;
        while(l<r){
            if(v[l]+v[r]==k){
                ans++;
                l++;
                r--;
            }
            else if(v[l]+v[r]<k) l++;
            else r--;
        }
        return ans;
    }
};


//1 3 3 3 4