class Solution {
public:
    int arrangeCoins(int n) {
        int left=1;
        int right=n;
        int ans=n;
        while(left<=right){
            int mid=left+(right-left)/2;
            long long value=1ll*mid*(mid+1)/2;
            if(value<=n){
                ans=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
    }
};