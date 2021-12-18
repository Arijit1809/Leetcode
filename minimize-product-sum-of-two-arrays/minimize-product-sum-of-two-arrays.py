class Solution:
    def minProductSum(self, nums1: List[int], nums2: List[int]) -> int:
        return sum([x*y for x,y in zip(sorted(nums1), sorted(nums2, reverse=True))])