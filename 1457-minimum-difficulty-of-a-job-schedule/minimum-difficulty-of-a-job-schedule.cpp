class Solution {
public:
    
    int find( vector<int>& job ,  int d , int start , int n,vector<vector<int>>&dp){
        if(dp[start][d] != -1) return dp[start][d];
        if( d == 1){
            int res = INT_MIN;
            for(int i = start ; i< n ; i++){
                res = max ( res , job [ i]);
            }
            return res;
        }
        else{
            int val = INT_MIN;
            int res = INT_MAX;
            
            for( int i = start ; i< n-d+1 ; i++){
                val = max ( val , job[i]);
                res = min ( res , val+find(job , d-1, i+1 , n,dp));
            }
            return dp[start][d] = res;
        }
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int size = jobDifficulty.size();

        vector<vector<int>>dp(size+1, vector<int>(d+1,-1));
        
        if(size < d) return -1;
        
        return find ( jobDifficulty , d, 0 , size,dp);
    }
};