class Solution {
public:
    pair<int,int>p[4]={{-1,0},{0,-1},{0,1},{1,0}};
    void flooding(vector<vector<char>>& board,int i,int j){
        board[i][j]='V';
        for(int k=0;k<4;k++){
            int in=i+p[k].first;
            int jn=j+p[k].second;
            if(in>=0 && jn>=0 && in<board.size() && jn<board[0].size() && board[in][jn]=='O'){
                flooding(board,in,jn);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            if(board[i][0]=='O') flooding(board,i,0);
        }
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O') flooding(board,i,m-1);
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O') flooding(board,0,j);
        }
        for(int j=0;j<m;j++){
            if(board[n-1][j]=='O') flooding(board,n-1,j);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='V') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};