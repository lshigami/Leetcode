class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int MAX=0;
        int i=0;
        int cnt;
        bool visited[256]={false};
        while(i<s.size()){
            cnt=1;
            int j=i+1;
            visited[s[i]]=true;
            while(j<s.size()){
                if(!visited[s[j]]){
                    visited[s[j]]=true;
                    cnt++;
                    j++;
                }
                else break;
            }
           // cout<<cnt<<endl;
            memset(visited,false,sizeof(visited));
            MAX=max(MAX,cnt);
            i++;
        }
        return MAX;
    }
};