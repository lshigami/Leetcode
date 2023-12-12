class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int>m;
        for(auto x:chars){
            m[x]++;
        }
        bool ok;
        int sum=0;
        for(auto x : words){
            ok=true;
            map<char,int> temp = m;
            for(auto c : x){
                if(temp[c]==0) {
                    ok=false;
                    break;
                }
                temp[c]--;
            }
            if(ok) sum+=x.size();
        }
        return sum;
    }
};
