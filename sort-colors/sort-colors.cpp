class Solution {
public:
    void sortColors(vector<int>& nums) {
  if (nums.empty())
    return;

  int pre = 0, b = 0, e = nums.size() - 1;
  while (b <= e) {
    if (nums[b] == 0) {
      swap(nums[pre++], nums[b++]);
    } else if (nums[b] == 1) {
      b++;
    } else {
      swap(nums[e--], nums[b]);
    }
  }
    }
};