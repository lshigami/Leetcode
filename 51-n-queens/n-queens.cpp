class Solution {
public:
    int row[20];

    void Try(vector<vector<string>>&ans,int col[], bool left[], bool right[],int n, int i){
        for(int j=0;j<n;j++){
            if(!left[i+j] && !right[n+i-j-1] && !col[j]){
                col[j]=left[i+j]=right[n+i-j-1]=true;
                row[i]=j;
                if(i==n-1) {
                    vector<string>temp;
                    for(int r=0;r<n;r++){
                        string s="";
                        for(int c=0;c<n;c++){
                            if(row[r]==c) s+="Q"; else s+=".";
                        }
                        temp.push_back(s);
                    }
                    ans.push_back(temp);

                }
                else Try(ans,col,left,right,n,i+1);
                col[j]=left[i+j]=right[n+i-j-1]=false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        int col[20];
        bool left[20],right[20];
        memset(row,false,sizeof(row));
        memset(col,false,sizeof(col));
        memset(left,false,sizeof(left));
        memset(right,false,sizeof(right));
        Try(ans,col,left,right,n,0);
        return ans;
    }
};
