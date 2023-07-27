class Solution {
public:
    int numRescueBoats(vector<int>& v, int limit) {
        sort(v.begin(),v.end());
        int cnt=0;
        int l=0;int r=v.size()-1;
        while(l<=r){
            if(l==r) {
                cnt++;
                break;
            }
            int sum=v[l]+v[r];
            if(sum>limit) {
                cnt++;
                r--;
            }
            else {
                cnt++;
                l++;
                r--;
            }
        }
        return cnt;
    }
};