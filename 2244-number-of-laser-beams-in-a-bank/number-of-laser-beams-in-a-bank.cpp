class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>devices;
        for(auto x:bank){
           int count=0;
           for(auto c:x){
               if(c=='1') ++count;
           }
           if(count!=0) devices.push_back(count);
        }
        int ans=0;
        for(int i=1;i<devices.size();i++){
            ans+=devices[i]*devices[i-1];
        }
        return ans;
    }
};