class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        for(auto x:v ){
            cout<<x<<" ";
        }
        cout<<endl;
        vector<vector<int>>ans;
        vector<vector<int>>null;
        for(int i=0;i<v.size();i+=3){
            vector<int>temp;
            if(i+1<v.size() && i+2<v.size() ){
                if(v[i+2]-v[i+1]<=k && v[i+1]-v[i]<=k && v[i+2]-v[i]<=k){
                     temp.push_back(v[i]);
                    temp.push_back(v[i+1]);
                    temp.push_back(v[i+2]);
                }
                else return null;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};