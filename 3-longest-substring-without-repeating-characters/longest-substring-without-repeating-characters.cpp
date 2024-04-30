class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int left=0;
        int ans=0;
        for(int right=0;right<s.size();right+=1){
            if(m[s[right]]==0) {
                m[s[right]]=1;
                ans=max(ans,right-left+1);
            }
            else{
                while(s[left]!=s[right]){
                    m[s[left]]=0;
                    left+=1;
                }
                left+=1;
                m[s[right]]=1;
            }
        }
        return ans;
    }
};