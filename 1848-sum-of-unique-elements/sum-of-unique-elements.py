class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        m={}
        ans=0
        for i in range (0,len(nums)):
            if nums[i] in m :
                m[nums[i]]+=1
            else :
                m[nums[i]]=1
        for i in range (0,len(nums)):
            if(m[nums[i]]==1) :
                ans+=nums[i]
        return ans