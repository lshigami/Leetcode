class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m={}
        for i in range(0,len(nums)):
            if target-nums[i] in m :
                return [m[target-nums[i]]+1,i+1]
            m[nums[i]]=i
        return []