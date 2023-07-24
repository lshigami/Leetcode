class Solution {
public:
    int totalNQueens(int n) {
        bool p[20];
        bool q[20];
        memset(p,false,sizeof(p));
        memset(q,false,sizeof(q));
        bool o[20];
        memset(o,false,sizeof(o));
        int cnt=0;
        Try(p,q,o,n,cnt,1);
        return cnt;
    }
    void Try(bool p[], bool q[], bool o[],int n, int &cnt, int i){
        for(int j=1;j<=n;j++){
            if(!p[i+j-1] && !q[i-j+n] && !o[j]){
                o[j]=true;
                q[i-j+n]=true;
                p[i+j-1]=true;
                if(i==n) cnt++;
                else Try(p,q,o,n,cnt,i+1);
                o[j]=q[i-j+n]=p[i+j-1]=false;
            }
        }
    }
};
