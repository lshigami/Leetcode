class Solution {
public:
    static bool cmp(string a,string b){
       return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>v;
        for(auto x:nums){
            v.push_back(to_string(x));
        }
        sort(v.begin(),v.end(),cmp);
        string ans="";
        for(auto x:v){
            ans+=x;
        }
        return ans[0]=='0' ? "0" : ans;
    }
};