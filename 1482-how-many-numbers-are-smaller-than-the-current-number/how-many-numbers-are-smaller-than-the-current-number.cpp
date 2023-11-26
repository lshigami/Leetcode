class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int,int>m;
        for(auto x:nums){
            m[x]++;
        }
        vector<int>v;
        for(auto x:nums){
            int cnt=0;
            for(int i=0;i<=100;i++){
                if(i<x && m[i]) cnt+=m[i];
            }
            v.push_back(cnt);
        }
        return v;
    }
};