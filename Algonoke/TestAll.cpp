#include "Algonoke.h"
#include <iostream>
#include <string>

void Check(bool statement, std::string err_info) {
  if (!statement) {
    std::cout << err_info << std::endl;
    exit(0);
  }
}

void TestKM() {
  using namespace Algo;
  {
    std::cout << "TestKM" << std::endl;
    int n = 4;
    double *cost = new double[n * n];
    for (int i = 0; i < n * n; i++) {
      cost[i] = 0.0;
    }
    for (int i = 0; i < n; i++) {
      cost[i * n + i] = -1.0;
    }
    std::vector<int> pas;
    MatchingKM(n, cost, pas);
    for (int i = 0; i < n; i++)
      std::cout << pas[i] << " ";
    std::cout << std::endl;
    delete[](cost);
  }
  // Sparse.
  {
    std::cout << "--------------------------------------" << std::endl;
    int n = 4;
    auto edges = new std::vector<std::pair<int, double> >[n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) {
          edges[i].emplace_back(j + n, 0.0);
        }
        else {
          edges[i].emplace_back(j + n, 1.0);
        }
      }
    }
    std::vector<int> pas;
    SparseMatchingKM(n, n * 2, edges, pas);
    for (int i = 0; i < n * 2; i++)
      std::cout << pas[i] << " ";
    std::cout << std::endl;
    delete[](edges);
  }
}

int main() {
  TestKM();
}