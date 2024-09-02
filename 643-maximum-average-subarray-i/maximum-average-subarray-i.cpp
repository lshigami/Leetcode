class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left=0;
        double avg=INT_MIN;
        int sum=0;
        for(int right=0;right<nums.size();right+=1){
            if(right>=k){
                sum-=nums[left++];
            }
            sum+=nums[right];
            if(right-left+1==k) avg=max(avg,1.0*sum/k);
        }
        return avg;
    }
};