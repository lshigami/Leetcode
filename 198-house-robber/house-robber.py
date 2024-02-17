class Solution:
    def rob(self, nums: List[int]) -> int:
        @lru_cache(maxsize=None)
        def rob_recursive(i):
            if i < 0:
                return 0
            return max(rob_recursive(i - 2) + nums[i], rob_recursive(i - 1))
        
        return rob_recursive(len(nums) - 1)
