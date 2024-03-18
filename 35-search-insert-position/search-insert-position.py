class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l=0
        r=len(nums)-1
        while(l<=r):
            m=(l+r)//2
            if nums[m]>=target:
                r=m-1
            else:
                l=m+1
        return r+1