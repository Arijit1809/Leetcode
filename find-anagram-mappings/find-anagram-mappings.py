class Solution:
    def anagramMappings(self, nums1: List[int], nums2: List[int]) -> List[int]:
        dic = {num2:index for index,num2 in enumerate(nums2)}
        ans = []
        for num1 in nums1:
            ans.append(dic[num1])
        return ans
        