class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>m;
        for(int i=0;i<arr2.size();i++){
            m[arr2[i]]=i;
        }
        for(int i=0;i<arr1.size();i++){
            if(!m.count(arr1[i])) m[arr1[i]]=1000+arr1[i];
        }
        sort(arr1.begin(),arr1.end(),[&](int a,int b)->bool{
            return m[a]<m[b];
        });
        return arr1;
    }
};