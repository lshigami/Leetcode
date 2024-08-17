class Solution {
public:
    int arrangeCoins(int n) {
        int left=1;
        int right=n;
        int ans=1;
        while(left<=right){
            int stair=left+(right-left)/2;
            long long needCoin=1ll*stair*(stair+1)/2;
            if(n>=needCoin){
                ans=stair;
                left=stair+1;
            }
            else{
                right=stair-1;
            }
        }
        return ans;
    }
};