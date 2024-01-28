class Solution {
public:
    int searchInsert(vector<int>& v, int target) {
        int l=0;
        int r=v.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(v[m]==target){
                return m;
            }
            else if(v[m]>target){
                r=m-1;
            }
            else {
                l=m+1;
            }
            
        }
       return l;
    }
};