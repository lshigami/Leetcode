class Solution {
public:
    bool valid(int mid,vector<int>bloomDay,int m,int k){
        int bouquets=0;
        int left=0;
        for(int right=0;right<bloomDay.size();right++){
            if(bloomDay[right]>mid) {
                left=right+1;
                continue;
            }
            if(right-left+1==k) {
                left=right+1;
                bouquets+=1;
                continue;
            }
        }
        cout<<bouquets;
        return bouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left=*min_element(bloomDay.begin(),bloomDay.end());
        int right=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(valid(mid,bloomDay,m,k)){
                right=mid-1;
                ans=mid;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};