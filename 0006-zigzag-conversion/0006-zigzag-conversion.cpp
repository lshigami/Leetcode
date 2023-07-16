class Solution {
public:
    string convert(string s, int n) {
        if(n==1) return s;
        vector<string>v(n,"");
    int tf=-1;
    int j=0;
    for(int i=0;i<s.size();i++){
        if(j==n-1 || j==0) tf*=-1;
        v[j]+= s[i];
        if(tf==1) j++;
        else j--;
    }
    string ans="";
    for(auto x:v){
        ans+=x;
    }
        return ans;
    }
};