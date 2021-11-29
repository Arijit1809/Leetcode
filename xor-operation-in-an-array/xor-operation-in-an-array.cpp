class Solution
{
    int xorOperationB(int n, int start)
    {
        if (n % 2 == 0)
            return (n / 2) & 1;
        else
            return ((n / 2) & 1) ^ (start + n - 1);
    }
    int xorOperationA(int n, int start)
    {
        if (start & 1)
            return (start - 1) ^ xorOperationB(n + 1, start - 1);
        else
            return xorOperationB(n, start);
    }
public:
    int xorOperation(int n, int start)
    {
        int ret = 2 * xorOperationA(n, start / 2);
        if (n & start & 1) ret++;
        return ret;
    }
};