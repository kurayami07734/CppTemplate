#include <algorithm>
#include <cmath>
#include <vector>
#pragma once
using namespace std;
int minimumAverageDifference(vector<int>& nums) {
  int sum = 0;
  for (int num : nums) sum += num;
  int min_ind = 0, min_diff = 1e6;
  int tally = 0;
  int n = nums.size();
  for (int i = 0; i < n - 1; i++) {
    tally += nums[i];
    int diff = abs(tally / (i + 1) - (sum - tally) / (n - i - 1));
    if (min_diff > diff) {
      min_diff = diff;
      min_ind = i;
    }
  }
  return min_ind;
}

int minSubArrayLen(int target, vector<int>& nums) {
  int len = 1e6, n = nums.size();
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += nums[j];
      if (sum == target) {
        len = min(len, j - i + 1);
        break;
      }
    }
  }
  return len == 1e6 ? 0 : len;
}
int captureForts(vector<int>& forts) {
  vector<int> ones, neg_ones;
  int cnt = 0;
  for (int i = 0; i < forts.size(); i++) {
    if (forts[i] == 1)
      ones.push_back(i);
    else if (forts[i] == -1)
      neg_ones.push_back(i);
  }
  int i = ones[0], j = neg_ones[0];
  auto start = forts.begin() + i;
  auto end = forts.begin() + j;
  if (i > j) swap(start, end);
  if (find(start + 1, end - 1, -1) == forts.end() ||
      find(start + 1, end - 1, 1) == forts.end())
    cnt = max(cnt, (int)count(start, end, 0));

  i = ones.back();
  j = neg_ones.back();
  start = forts.begin() + i;
  end = forts.begin() + j;
  if (i > j) swap(start, end);
  if (find(start + 1, end - 1, -1) == forts.end() ||
      find(start + 1, end - 1, 1) == forts.end())
    cnt = max(cnt, (int)count(start, end, 0));

  return cnt;
}