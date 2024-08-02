class Solution {
public:
    int mySqrt(int x) {
        int left=0;
        int right=x;
        int ans=x;
        while(left<=right){
            long long mid=(left+right)/2;
            if(mid*mid>x){
                ans=mid;
                right=mid-1;
            }
            else if(mid*mid==x) return mid;
            else left=mid+1;
        }
        return right;
    }
};