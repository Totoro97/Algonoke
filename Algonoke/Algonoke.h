#pragma once
#include <vector>

namespace Algo {

// Mincost of matching!
void MatchingKM(int size, double *bi_cost, std::vector<int> &pas);
void SparseMatchingKM(int size, int ano_size, std::vector<std::pair<int, double> > *edges, std::vector<int> &pas);
}