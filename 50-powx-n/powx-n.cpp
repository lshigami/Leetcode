class Solution {
public:
    double myPow(double x, long long n) {
        if(n==0) return 1;
        double X=myPow(x,n/2);
        if(n>0){
            if(n%2==0) return 1.0*X*X;
            else return 1.0*X*X*x;
        }else{
            return 1.0/myPow(x,-n);
        }
    }
};