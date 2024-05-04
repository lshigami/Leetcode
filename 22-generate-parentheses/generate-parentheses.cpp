class Solution {
public:
    bool check(string s) {
        int sum = 0;
        for (auto x : s) {
            if (x == '(') sum += 1;
            else sum -= 1;
            if (sum < 0) return false;
        }
        return sum == 0;
    }
    void BackTrack(vector<string>&ans,string temp,string base,int i,int n){
        for(auto c:base){
            temp+=string(1,c);
            if(i==n) {
                if(check(temp)) ans.push_back(temp);
            }
            else BackTrack(ans,temp,base,i+1,n);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string base="()";
        vector<string>ans;
        BackTrack(ans,"",base,1,n*2);
        return ans;
    }
};