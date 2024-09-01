class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength=0;
        unordered_map<char,int>m;
        int left=0;
        for(int right=0;right<s.size();right+=1){
            m[s[right]]+=1;
            while(m[s[right]]>1){
                if(m[s[left]]==1) m.erase(s[left]);
                else m[s[left]]-=1;
                left+=1;
            }
            maxLength=max(maxLength,right-left+1);
        }
        return maxLength;
    }
};