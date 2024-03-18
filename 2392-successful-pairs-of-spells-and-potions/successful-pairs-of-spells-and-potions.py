class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        def BinarySearch(nums,x):
            l=0
            r=len(nums)-1
            while l<=r:
                m=(l+r)//2
                if nums[m]>=x:
                    r=m-1
                elif nums[m]<x:
                    l=m+1
            return r+1
        ans=[]
        res=0
        potions.sort()
        n=len(potions )
        for i in range (0,len(spells)):
            res=0
            index=BinarySearch(potions,success/spells[i])
            print(index)
            if index<=n:
                res=n-index
            ans.append(res)
        return ans
