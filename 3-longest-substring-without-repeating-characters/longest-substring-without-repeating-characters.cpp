class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int left=0;
        int right=0;
        int maxSize=0;
        for(auto x:m) cout<<x.first<<" "<<x.second<<endl;
        while(right<s.size()){
            m[s[right]]+=1;
            while(m[s[right]]>1){
                m[s[left]]-=1;
                left+=1;
            }
            maxSize=max(maxSize,right-left+1);
            right+=1;
        }
        return maxSize;
    }
};