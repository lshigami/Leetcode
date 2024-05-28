class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans=0;
        int left=0;
        int right=0;
        int consumer=0;
        for(right=0;right<s.size();right+=1){
            consumer+=abs(t[right]-s[right]);
            while(consumer>maxCost){
                consumer-=abs(t[left]-s[left]);
                left+=1;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};