class Solution {
public:
    bool possible(int mid,vector<int>piles,int h){
        long long hours=0;
        for(auto x: piles){
            hours += ceil((double)x/mid);
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        int speed=right;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(possible(mid,piles,h)){
                speed=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return speed;
    }
};