class Solution:
    def bitwiseComplement(self, N: int) -> int:
        if N == 0:
            return 1
        todo, bit = N, 1
        while todo:
            # flip current bit
            N = N ^ bit
            # prepare for the next run
            bit = bit << 1
            todo = todo >> 1
        return N