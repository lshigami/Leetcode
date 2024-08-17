class Solution {
public:
    bool possible(int maxWeight,vector<int>weights,int days){
        int currentWeight=0;
        int day=1;
        for(auto w:weights){
            currentWeight+=w;
            if(currentWeight>maxWeight){
                currentWeight=w;
                if(currentWeight>maxWeight) return false;
                day+=1;
            }
        }
        return day<=days;
    }
    //1 2 2 3 4 4
    int shipWithinDays(vector<int>& weights, int days) {
        // sort(weights.begin(),weights.end());
        int left=0;
        int right=accumulate(weights.begin(),weights.end(),0);
        int minWeight=right;
        while(left<=right){ 
            int mid=left+(right-left)/2;
            if(possible(mid,weights,days)){
                minWeight=mid;
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return minWeight;
    }
};