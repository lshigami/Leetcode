class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int countOnes=0;
        int left=0;
        int right=0;
        int count=0;
        int maxOnes=0;
        for(auto x: nums) {
            if(x==1) countOnes+=1;
        }
        for(int i=0;i<countOnes;i++){
            if(nums[i]==1) count+=1;
        }
        maxOnes=count;
        for(int i=countOnes;i<2*n;i++){
           if(nums[i%n]==1) count+=1;
            if(nums[left%n]==1) count-=1;
            left+=1;
            maxOnes=max(maxOnes,count); 
        }
        return countOnes-maxOnes;
    }
};
//Premium : 
// class Solution {
// public:
//     int minSwaps(vector<int>& data) {
//         int countOnes=0;
//         for(auto x:data){
//             if(x==1) countOnes+=1;
//         }
//         int index=0;
//         int left=0;
//         int maxOnes=0;
//         int count=0;
//         for(int right=0;right<countOnes;right+=1){
//             if(data[right]==1){
//                 count+=1;
//             }
//         }
//         maxOnes=max(maxOnes,count);
//         for(int right=countOnes;right<data.size();right+=1){
//             if(data[right]==1){
//                 count+=1;
//             }
//             if(data[left]==1) count-=1;
//             left+=1;
//             if(count>maxOnes){
//                 maxOnes=count;
//                 index=left;
//             }
//         }
//         return countOnes-maxOnes;
//     }
// };