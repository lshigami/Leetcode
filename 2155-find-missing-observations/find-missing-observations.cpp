class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int needed=mean*(n+m);
        for(auto x:rolls) needed-=x;
        vector<int>v;
        if(n*6<needed || n*1>needed) return v;
        int e=needed/n;
        for(int i=1;i<=n;i++) v.push_back(e);
        needed=needed-e*n;
        int i=0;
        while(needed){
            v[i++]+=1;
            needed-=1;
        }
        return v;
    }
};