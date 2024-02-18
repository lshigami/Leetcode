class Solution:
    def largestSumAfterKNegations(self, v: List[int], k: int) -> int:
        v.sort()
        for i in range(len(v)):
            if v[i] < 0 and k > 0:
                v[i] *= -1
                k -= 1
        min_val = min(v)
        sum_val = sum(v)
        if k % 2 != 0:
            sum_val -= min_val * 2
        return sum_val