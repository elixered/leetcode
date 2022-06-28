class Solution {
public:
int minDifference(vector<int>& nums) {
  int const N = nums.size();

  // For up to four numbers, we can always make them all equal.
  if (N <= 4) return 0;

  // Shift the four smallest numbers to the beginning
  // and the four largest numbers to the end.
  std::partial_sort(nums.begin(), nums.begin() + 4, nums.end());
  std::partial_sort(nums.rbegin(), nums.rbegin() + 4, nums.rend(), std::greater<int>());

  // Try all four possible ways to pick our 3 moves.
  int result = INT_MAX;
  for (int l = 0; l <= 3; ++l)
    result = std::min(result, nums[N-4+l] - nums[l]);
  return result;
}
};