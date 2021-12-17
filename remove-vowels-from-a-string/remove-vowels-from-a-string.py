class Solution:
    def removeVowels(self, s: str) -> str:
        ans = ""
        for letter in s:
            if letter not in 'aeiou':
                ans+=letter
        return ans