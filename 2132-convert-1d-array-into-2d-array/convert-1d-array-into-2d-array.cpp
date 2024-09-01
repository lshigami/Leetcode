class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>res;
        int k=0;
        if(m*n!=original.size()) return res;
        for(int i=1;i<=m;i++){
            vector<int>temp;
            for(int j=1;j<=n;j++){
                temp.push_back(original[k++]);
            }
            res.push_back(temp);
        }
        return res;
    }
};