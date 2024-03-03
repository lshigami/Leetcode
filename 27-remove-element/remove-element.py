class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        left = 0
        right = len(nums) - 1
        while left <= right:
            if nums[right] == val:
                nums.pop()
                right -= 1
            elif nums[left] == val:
                nums[left], nums[right] = nums[right], nums[left]
            else:
                left += 1
                
        return len(nums)