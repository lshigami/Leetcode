class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        for(auto x:nums1){
            m1[x]++;
        }
        for(auto x:nums2){
            m2[x]++;
        }
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>tmp;

        for(auto x:m1){
            if(m2[x.first]==0) temp.push_back(x.first);
        }

        for(auto x:m2){
            if(m1[x.first]==0) tmp.push_back(x.first);
        }
        ans.push_back(temp);
        ans.push_back(tmp);

        return ans;
    }
};