class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = A.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                for(int k=j;k<n;k++){
                    if((A[i]&A[j]&A[k])==0){
                        if(i==j && j==k){
                            cnt++;
                        }else if(i==j || i==k || j==k){
                            cnt+=3;
                        }else{
                            cnt+=6;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};