class Solution {
public:
    int totalNQueens(int n) {
        bool col[20],left[20],right[20];
        memset(col,false,sizeof(col));
        memset(left,false,sizeof(left));
        memset(right,false,sizeof(right));
        int cnt=0;
        Try(col,left,right,n,cnt,0);
        return cnt;
    }
    void Try(bool col[], bool left[], bool right[],int n,int &cnt, int i){
        for(int j=0;j<n;j++){
            if(!left[i+j] && !right[n+i-j-1] && !col[j]){
                col[j]=left[i+j]=right[n+i-j-1]=true;
                if(i==n-1) cnt++;
                else Try(col,left,right,n,cnt,i+1);
                col[j]=left[i+j]=right[n+i-j-1]=false;
            }
        }
    }
};