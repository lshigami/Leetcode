class Solution:
    def searchRange(self, nums: List[int], x: int) -> List[int]:
        l=0
        r=len(nums)-1
        a=-1
        b=-1
        while(l<=r):
            m=(l+r)//2
            if nums[m]>=x:
                if(nums[m]==x) :
                    a=1
                r=m-1
            else :
                l=m+1
        i=r+1
        l=0
        r=len(nums)-1
        while(l<=r):
            m=(l+r)//2
            if nums[m]<=x:
                if(nums[m]==x) :
                    b=1
                l=m+1
            else:
                 r=m-1
        j=l-1
        return [-1 if a == -1 else i, -1 if b == -1 else j]
