class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        vector<int>v1;
        vector<int>v2;
        for(auto x:word1){
            m1[x]++;
        }
        for(auto x:word2){
            m2[x]++;
        }
        for(auto x:m1){
            if(m2[x.first]==0){
                return false;
            }
            v1.push_back(m1[x.first]);
            v2.push_back(m2[x.first]);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return v1==v2;
    }
};