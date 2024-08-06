class Solution {
    vector<int>candidates;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        this->candidates=candidates;
        vector<int>temp;
        vector<vector<int>>res;
        int sum=0;
        backtrack(0,sum,target,temp,res);
        return res;
    }
    void backtrack(int index,int sum,int target,vector<int>temp,vector<vector<int>>&res){
        for(int i=index;i<candidates.size();i++){
            int x=candidates[i];
            sum+=x;
            temp.push_back(x);
            if(sum==target){
                res.push_back(temp);
            }else if(sum<target){
                backtrack(i,sum,target,temp,res);
            }
            sum-=x;
            temp.pop_back();
        }
    }
};