class Solution {
public:
   double myPow(double x, long long n) {
    if(n==0) return 1;
    double temp= myPow(x,n/2);
    if(n>0){
        if(n%2==0) return 1.0*temp*temp;
        else return 1.0*temp*temp*x;
    }
    else{
        return 1.0/myPow(x,-n);
    }
    }

};