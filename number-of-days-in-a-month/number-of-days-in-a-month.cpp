class Solution {
public:
  int numberOfDays(int Y, int M) {
    if (M != 2)
      return 31 - (M & 1) ^ (M <= 7);
    return 28 + int((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0);
  }
};