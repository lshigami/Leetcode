class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left=1;
        long long right=sqrt(c);
        if((int)sqrt(c)*(int)sqrt(c)==c) {
            cout<<sqrt(c);
            return true;
        }
        while(left<=right){
            long long product=(long long)left*left+ (long long)right*right;
            if(product>c) right-=1;
            else if (product<c) left+=1;
            else {
                cout<<left<<" "<<right;
                return true;
            }
        }
        return false;
    }
};