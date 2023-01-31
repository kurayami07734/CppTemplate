#include <iostream>
#include <vector>

#include "networkDelayTime.cpp"
using namespace std;

int main() {
  vector<vector<int>> ip = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
  cout << networkDelayTime(ip, 4, 2) << endl;
}