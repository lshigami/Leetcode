class Solution {
public:

    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int needed=mean*(n+m);
        for(auto x:rolls) needed-=x;
        cout<<needed<<endl;
        vector<int>v;
        if(n*6<needed || n*1>needed) return v;
        int e=needed/n;
        for(int i=1;i<=n;i++) v.push_back(e);
        for(auto x:v){
            cout<<x<<" ";
        }
        needed=needed-e*n;
        for(auto &x:v){
            if(needed==0) return v;
            int val=min(6-x,needed);
            needed-=val;
            x+=val;
        }
        return v;
    }
};