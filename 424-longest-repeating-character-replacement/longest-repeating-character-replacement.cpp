class Solution {
public:
    int slidingChar(char c,string s,int k){
        int ans=1;
        int left=0;
        int differ=0;
        for(int right=0;right<s.size();right+=1){
            if(s[right]!=c) differ+=1;
            while(differ>k){
                if(s[left++]!=c) differ-=1;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
    int characterReplacement(string s, int k) {
        set<char>se;
        for(auto x:s) se.insert(x);
        int ans=1;
        for(auto x:se){
            ans=max(ans,slidingChar(x,s,k));
        }
        return ans;
    }
};