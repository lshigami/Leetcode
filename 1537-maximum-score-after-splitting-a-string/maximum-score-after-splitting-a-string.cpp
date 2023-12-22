class Solution {
public:
    int maxScore(string s) {
        int count_one=count(s.begin(),s.end(),'1');
        if(count_one==0) return s.size()-1;
        int count_zero=0;
        int ans=INT_MIN;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0') count_zero++;
            else count_one--;
            ans=max(ans,count_one+count_zero);
        }
        return ans;
    }
};