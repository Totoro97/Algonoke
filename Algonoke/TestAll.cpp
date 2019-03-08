#include "Algonoke.h"
#include <iostream>

void TestKM() {
  using namespace Algo;
  std::cout << "TestKM" << std::endl;
  int n = 4;
  double *cost = new double[n * n];
  for (int i = 0; i < n * n; i++) {
    cost[i] = 1.0;
  }
  std::vector<int> pas;
  MatchingKM(n, cost, pas);
  delete[](cost);
}

int main() {
  TestKM();
}