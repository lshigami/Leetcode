class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        int i;
        for(i=s.size()-1;i>=0;i--){
            if(isalpha(s[i])) break;
        }
        for(int j=i;j>=0;j--){
            if(s[j]!=' ') ans++;
            else return ans;
        }
        return ans;
    }
};