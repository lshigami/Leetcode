class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2) return nums.size();
        int k=0;
        for(int i=0;i<nums.size();){
            int j=i+1;
            while(j<nums.size() &&nums[i]==nums[j]) j+=1;
            for(int v=i;v<min(j,i+2);v++){
                nums[k++]=nums[v];
            }
            i=j;
        }
        return k;
    }
};