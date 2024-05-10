class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                v.push_back({arr[i],arr[j]});
            }
        }
        sort(v.begin(),v.end(),[](pair<int,int>a,pair<int,int>b)->bool{
            return 1.0*a.first/a.second < 1.0*b.first/b.second ;
        });  
        vector<int>ans;
        ans.push_back(v[k-1].first);
        ans.push_back(v[k-1].second);
        return ans;
    }
};