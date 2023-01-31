#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#include <vector>
#pragma once

using namespace std;

int rangeAnd(int left, int right) {
  bitset<32> b1(left), b2(right), b3(0);
  for (int i = 31; i >= 0; i--) {
    if (b1[i] == b2[i])
      b3[i] = b1[i];
    else
      break;
  }
  return b3.to_ulong();
}
long long maxKelements(vector<int>& nums, int k) {
  long long score = 0;
  priority_queue<int> pq(nums.begin(), nums.end());
  while (k > 0) {
    int top = pq.top();
    pq.pop();
    score += top;
    int newVal = top % 3 != 0 ? top / 3 + 1 : top / 3;
    pq.push(newVal);
    k--;
  }
  return score;
}
vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int orangesRotting(vector<vector<int>>& grid) {
  int R = grid.size(), C = grid[0].size();
  queue<pair<int, int>> q;
  q.push({-1, -1});  // to count time
  int freshCount{0}, time{-1};
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (grid[i][j] == 1) freshCount++;
      if (grid[i][j] == 2) q.push({i, j});
    }
  }
  while (!q.empty()) {
    int r = q.front().first, c = q.front().second;
    q.pop();
    if (r == -1) {
      time++;
      if (!q.empty()) q.push({-1, -1});
    } else {
      for (int i = 0; i < dirs.size(); i++) {
        int row = r + dirs[i][0];
        int col = c + dirs[i][1];
        if (row < 0 || row >= R || col < 0 || col >= C) continue;
        if (grid[row][col] == 1) {
          grid[row][col] = 2;
          freshCount--;
          q.push({row, col});
        }
      }
    }
  }
  return freshCount == 0 ? time : -1;
}
vector<int> helper(vector<int>& v) {
  int n = v.size();
  int i = 0, k = 0;
  vector<vector<int>> m(n + 1);
  for (i = 0; i < n; i++) {
    if (v[i] > n) {
      cout << "-1\n";
      return {};
    }
    m[v[i]].push_back(i);
  }
  k = 1;
  for (i = 1; i <= n; i++) {
    if (m[i].size() > 0) {
      sort(m[i].begin(), m[i].end());
      for (int ind : m[i]) {
        v[ind] = k;
        if (m[i].size() == n) k++;
      }
      k++;
    }
  }
  return v;
}