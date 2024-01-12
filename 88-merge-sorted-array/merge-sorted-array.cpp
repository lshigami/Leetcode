class Solution {
public:
    void merge(vector<int>& v1, int m, vector<int>& v2, int n) {
        int k=m+n-1;
        int i=m-1;
        int j=n-1;
        while(i>=0 && j>=0){
            if(v2[j]>v1[i]) v1[k--]=v2[j--];
            else v1[k--]=v1[i--];
        }
        while(j>=0){
            v1[k--]=v2[j--];
        }
    }
};