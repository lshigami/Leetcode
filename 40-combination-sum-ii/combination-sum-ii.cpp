class Solution {
    vector<int>candidates;
    vector<vector<int>>res;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        this->candidates=candidates;
        vector<int>temp;
        backtrack(temp,0,0,target);
        return res;
    }
    void backtrack(vector<int>temp,int sum,int index, int target){
        for(int i=index;i<candidates.size();i++){
            int x=candidates[i];
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            sum+=x;
            temp.push_back(x);
            if(sum==target){
                res.push_back(temp);
            }else if(sum<target){
                backtrack(temp,sum,i+1,target);
            }
            sum-=x;
            temp.pop_back();
        }
    }
};