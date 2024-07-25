class Solution {
public:
    bool judgeSquareSum(int c) {
        //b=sqrt(c-a*a);
        for(int a=0;a<=sqrt(c);a+=1){
            double b=1.0*sqrt(c-a*a);
            if(fmod(b,1)==0) return true;
        }
        return false;
    }
};