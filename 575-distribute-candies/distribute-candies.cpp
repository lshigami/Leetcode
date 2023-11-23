class Solution {
public:
    int distributeCandies(vector<int>& v) {
        map<int,int>m;
        for(auto x:v){
            m[x]++;
        }
        int candies=v.size()/2;
        if(m.size() >=candies) return candies;
        else return m.size();
    }
};