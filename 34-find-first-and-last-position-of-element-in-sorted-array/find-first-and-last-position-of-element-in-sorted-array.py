class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def BinarySearch(nums,x,isFirst):
            l=0
            r=len(nums)-1
            res=-1
            while l<=r:
                m=(l+r)//2
                if nums[m]>x:
                    r=m-1
                elif nums[m]<x:
                    l=m+1;
                else :
                    res=m
                    if isFirst:
                        r=m-1
                    else :
                        l=m+1
            return res
        first=BinarySearch(nums,target,True)
        last=BinarySearch(nums,target,False)
        return [first,last]