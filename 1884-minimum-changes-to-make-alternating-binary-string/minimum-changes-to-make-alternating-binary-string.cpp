class Solution {
public:
    int minOperations(string s) {
        int missmatched=0;
        for(int i=0;i<s.size();i++){
            if(i%2==0){
                if(s[i]=='1') missmatched++;
            }
            else {
                if(s[i]=='0') missmatched++;
            }
        }
        return min(missmatched,(int)s.size()-missmatched);
    }
};