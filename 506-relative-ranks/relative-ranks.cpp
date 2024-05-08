class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>v(score.begin(),score.end());
        sort(score.begin(),score.end(),greater<int>());
        vector<string>ans(score.size());
        map<int,string>m;
        for(int i=0;i<score.size();i++){
            if(i==0) m[score[i]]="Gold Medal";
            else if(i==1) m[score[i]]="Silver Medal";
            else if(i==2) m[score[i]]="Bronze Medal";
            else m[score[i]]=to_string(i+1);
        }
        for(int i=0;i<v.size();i++){
            ans[i]=m[v[i]];
        }
        return ans;
    }
};