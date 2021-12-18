class Solution:
    def maxNumberOfApples(self, arr: List[int]) -> int:
        arr.sort()
        apples = units = 0

        for _, weight in enumerate(arr):
            units += weight
            if units > 5000:
                break

            apples += 1
        return apples