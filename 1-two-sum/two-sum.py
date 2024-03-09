class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m = {}
        for i in range(len(nums)):
            m[nums[i]] = i
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in m and m[complement] != i:
                return [i, m[complement]]
        return []  # Trường hợp không tìm thấy cặp số thỏa mãn
