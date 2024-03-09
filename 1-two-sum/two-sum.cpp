class Solution {
public:
 vector<int> twoSum(vector<int>& v, int target) {
    map<int,int>m;
    for(int i=0;i<v.size();i++){
        m[v[i]]=i;
    }
    vector<int>ans;
    for(int i=0;i<v.size();i++){
        if(m.find(target-v[i]) != m.end() && m[target-v[i]] != i) {
            ans.push_back(i);
            ans.push_back(m[target-v[i]]);
            break;
        }
    }
    return ans;
}
};