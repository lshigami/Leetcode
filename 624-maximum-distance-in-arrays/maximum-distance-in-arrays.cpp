class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int MIN=arr[0][0];
        int MAX=arr[0].back();
        int maxDistance=0;
        for(int i=1;i<arr.size();i++){
            maxDistance=max({maxDistance,abs(MAX-arr[i][0]),abs(MIN-arr[i].back())});
            MAX=max(MAX,arr[i].back());
            MIN=min(MIN,arr[i][0]);
        }
        return maxDistance;
    }
};