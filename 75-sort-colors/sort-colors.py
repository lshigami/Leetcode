class Solution:
    def sortColors(self, v: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l=0
        r=len(v)-1
        k=0
        while k<=r:
            if v[k]==0:
                v[l], v[k] = v[k], v[l]
                l+=1
                k+=1
            elif v[k]==1:
                k+=1
            else :
                v[r], v[k] = v[k], v[r]
                r-=1
