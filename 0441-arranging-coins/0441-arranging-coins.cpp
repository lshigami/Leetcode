class Solution {
public:
    int arrangeCoins(int val) {
        return search(0,INT_MAX-1,val);
    }
    int search(long l, long r, long val){
        long ans=1;
        while(l<=r){
            long m=(l+r)/2;
            if((m*(m+1))/2 <= val){
                ans=m;
                l=m+1;
            }
            else r=m-1;
        }
        return ans;
    }
};