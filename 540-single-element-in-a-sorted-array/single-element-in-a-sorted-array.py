class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        low=0
        high=(len(nums)//2-1)
        res=len(nums)-1
        while low<=high:
            mid=(low+high)//2
            if nums[mid*2]<nums[mid*2+1]:
                res=mid*2
                high=mid-1
            else :
                low=mid+1
        return nums[res]