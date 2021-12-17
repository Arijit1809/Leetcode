class Solution:
    def calculateTime(self, keyboard: str, word: str) -> int:
        d = {c:pos for pos, c in enumerate(keyboard)}
        ret = 0
        last = 0
        for c in word:
            ret += abs(d[c]-last)
            last = d[c]
        return ret