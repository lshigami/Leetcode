class Solution {
public:
    vector<int> sortArray(vector<int>& v) {
        MergeSort(v,0,v.size()-1);
        return v;
    }
    void Merge(vector<int>&v,int l,int m, int r){
        vector<int>v1(v.begin()+l,v.begin()+m+1);
        vector<int>v2(v.begin()+m+1,v.begin()+r+1);
        int x=0;
        int y=0;
        int i=l;
        while(x<v1.size() && y<v2.size()){
            if(v1[x]<v2[y]) v[i++]=v1[x++];
            else v[i++]=v2[y++];
        }
        while(x<v1.size())  v[i++]=v1[x++];
        while(y<v2.size())  v[i++]=v2[y++];
    }
    void MergeSort(vector<int>& v, int l, int r){
        if(l<r){
            int m=(l+r)/2;
            MergeSort(v,l,m);
            MergeSort(v,m+1,r);
            Merge(v,l,m,r);
        }
    }
};