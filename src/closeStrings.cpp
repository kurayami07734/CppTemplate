#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#pragma once
using namespace std;
bool closeStrings(string word1, string word2) {
  if (word1.size() != word2.size()) return false;
  unordered_map<char, int> m1, m2;
  for (char c : word1) m1[c]++;
  for (char c : word2) m2[c]++;
  vector<int> red1, red2;
  for (auto i : m1) red1.push_back(i.second);
  for (auto i : m2) red2.push_back(i.second);
  sort(red1.begin(), red1.end());
  sort(red2.begin(), red2.end());
  return red1 == red2;
}
string addStrings(string a, string b) {
  if (b.size() > a.size()) swap(a, b);

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  int i = 0, carry = 0;
  for (i = 0; i < b.size(); i++) {
    int sum = (a[i] - '0') + (b[i] - '0') + carry;
    a[i] = sum % 10 + '0';
    carry = sum / 10;
  }
  while (i < a.size() && carry != 0) {
    int sum = (a[i] - '0') + carry;
    a[i] = sum % 10 + '0';
    carry = sum / 10;
    i++;
  }
  if (carry != 0) a.push_back(carry + '0');
  reverse(a.begin(), a.end());
  return a;
}
string generateKey(string s) {
  vector<int> freq(26, 0);
  for (char c : s) freq[c - 'a']++;
  string res;
  for (int i = 0; i < 26; i++) res += freq[i] + '0';
  return res;
}

vector<int> findAnagrams(string s, string p) {
  unordered_map<string, vector<int>> m;
  string k = generateKey(p);
  m[k] = {};
  for (int i = 0; i + p.size() <= s.size(); i++) {
    m[generateKey(s.substr(i, p.size()))].push_back(i);
  }
  return m[k];
}
int palin(int ind, string s) {
  int longest = 1;
  int l = ind - 2, r = ind;
  while (s[l] == s[r] && l >= 0 && r < s.size()) {
    l--;
    r++;
    if ((r - l + 1) % 2 != 0) longest = max(longest, r - l + 1);
  }
  return longest;
}
