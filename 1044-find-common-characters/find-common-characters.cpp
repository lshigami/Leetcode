class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        map<char,int>m;
        vector<string>ans;
        if(words.size()==0) return ans;
        for(auto c:words[0]){
            m[c]+=1;
        }
        for(int i=1;i<words.size();i++){
            map<char,int>temp;
            for(auto x:words[i]){
                temp[x]+=1;
            }
            for(auto &x:m){
                char c=x.first;
                if(temp.count(c)==0) m[c]=0;
                else{
                    m[c]=min(m[c],temp[c]);
                }
            }
        }
        for(auto x:m){
            for(int i=0;i<x.second;i++){
                ans.push_back(string(1,(x.first)));
            }
        }
        return ans;
    }
};

/*
ll : 2
e:1

roler :
r:2
o:1
l:1
e:1

*/