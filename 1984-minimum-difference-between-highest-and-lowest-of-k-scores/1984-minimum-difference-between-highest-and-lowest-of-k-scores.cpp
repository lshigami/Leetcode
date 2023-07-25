class Solution {
public:
    int minimumDifference(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        int l=0;
        int r=k-1;
        int MIN=INT_MAX;
        while(r<v.size()){
            MIN=min(MIN,(v[r]-v[l]));
            l++;
            r++;
        }
        return MIN;
    }
};