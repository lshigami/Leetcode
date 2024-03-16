class Solution:
    def arrangeCoins(self, n: int) -> int:
        low=1
        high=n
        while(low<=high):
            mid = (low+high)//2
            if n< (mid*(mid+1)//2):
                high=mid-1
            elif n>=(mid*(mid+1)//2):
                low=mid+1
        return low-1