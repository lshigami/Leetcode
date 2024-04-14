class Solution {
public:
    int findPeakElement(vector<int>& v) {
        if(v.size()==1) return 0;
        if(v.size()==2) {
            if(v[0]>v[1]) return 0;
            else if(v[1]>v[0]) return 1;
            else return -1;
        }
        if(v[0]>v[1]) return 0;
        if(v[v.size()-1]>v[v.size()-1-1]) return v.size()-1;
        int l=0;
    int r=v.size()-1;
    while(l<=r){
        int m=(l+r)/2;
        if(m+1<v.size() && m-1>=0  && v[m]>v[m+1] && v[m]>v[m-1]) return m;
        else if(m-1>=0 && v[m]<v[m-1]) r=m-1;
        else if(m+1<v.size() && v[m]<v[m+1]) l=m+1;
        else l=m+1;
    }
    return -1;
    }
};