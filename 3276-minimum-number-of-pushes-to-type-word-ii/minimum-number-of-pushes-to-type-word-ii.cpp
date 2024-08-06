class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>m;
        for(auto x:word){
            m[x]+=1;
        }
        sort(word.begin(),word.end(),[&m](char a,char b){
            if(m[a]==m[b]) return a<b;
            else return m[a]>m[b];
        });
        int cost=1;
        int cnt=8;
        int sum=0;
        for(auto x:word){
            if(m[x]==0) continue;
            if(cnt==0) {
                cost+=1;
                cnt=8;
            }
            sum+=m[x]*cost;
            m[x]=0;
            cnt-=1;
        }
        return sum;
    }
};