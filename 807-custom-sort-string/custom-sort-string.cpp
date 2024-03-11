class Solution {
public:
    string customSortString(string order, string s) {
       unordered_map<char,int>m;
       for(auto x:s){
           m[x]+=1;
       }
       string ans;
       for(auto x:order){
           if(m[x]){
               while(m[x]){
                   ans+=string(1,x);
                   m[x]--;
               }
           }
       }
       for(auto x:s){
           if(m[x]) ans+=string(1,x);
       }
       return ans;
    }
};