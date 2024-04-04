class Solution {
public:
    int flip_bit(int s, int idx){
        s=s^(1<<idx);
        return s;
    }
    int flip(string s,int bin, int& mask, int n, int m) {
        for (int i = 0; i < n * m; i++) {
            if ((mask >> i) & 1) {
                bin=flip_bit(bin,i);
                if(i-m>=0) bin=flip_bit(bin,i-m);
                if(i+m < n*m) bin=flip_bit(bin,i+m);
                if(i%m <m-1 ) bin=flip_bit(bin,i+1);
                if(i%m >0) bin=flip_bit(bin,i-1); 
            }
        }
        if(bin==0) return __builtin_popcount(mask); else return -1;
    }
    int minFlips(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = n * m + 1;
        string s = converMatrixToString(mat);
        int bin = stoi(s,0,2);
        for (int mask = 0; mask < (1 << (n * m)); mask++) {
            int f = flip(s,bin,mask,n,m);
            if (f != -1) {
                ans = min(ans, f);
            }
        }
        return ((ans == n * m + 1) ? -1 : ans);
    }
    string converMatrixToString(vector<vector<int>>& mat) {
        string ans = "";
        for (int i = 0; i < mat.size(); i++) {
            for(int j=0;j<mat[0].size();j++){
                ans += to_string(mat[i][j]);
            }
        }
        return ans;
    }
};