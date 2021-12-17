class Solution:
    def isArmstrong(self, N: int) -> bool:
        n_str = str(N)
        k = len(n_str)
        return sum(int(i)**k for i in n_str) == N