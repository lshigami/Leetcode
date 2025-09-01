class Solution {
public:
    int size(int n){
        int cnt=0;
        while(n){
            cnt++;
            n=n/10;
        }
        return cnt;
    }
    int sumUp(int n){
        int sum=0;
        int sz = size(n);
        while(n){
            sum+=1*pow(n%10,sz);
            n/=10;
        }
        return sum;
    }
    bool isArmstrong(int n) {
        
        return sumUp(n)==n;
    }
};