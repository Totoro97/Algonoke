#include "Algonoke.h"
#include <algorithm>
#include <iostream>

namespace Algo {

bool HavePathKM(int i, int n, double *edge,
              std::vector<double> &slk, std::vector<int> &vis_l,
              std::vector<int> &vis_r, std::vector<double> &mark_l, std::vector<double> &mark_r,
              std::vector<int> &p) {
  vis_l[i] = 1;
  for (int j = 0; j < n; j++) {
    if (std::abs(edge[i * n + j] - mark_l[i] - mark_r[j]) < 1e-3) {
      if (vis_r[j])
        continue;
      vis_r[j] = 1;
      if (p[j] == -1 || HavePathKM(p[j], n, edge, slk, vis_l, vis_r, mark_l, mark_r, p)) {
        p[j] = i;
        // std::cout << "Yes " << i << " " << j << std::endl;
        return true;
      }
    }
    else {
      slk[j] = std::min(slk[j], edge[i * n + j] - mark_l[i] - mark_r[j]);
    }
}
return false;
}

void MatchingKM(int size, double *bi_cost, std::vector<int> &pas) {
  int n = size;
  pas.resize(n, -1);
  std::vector<double> mark_l(n, 1e9);
  std::vector<double> mark_r(n, 0.0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mark_l[i] = std::min(mark_l[i], bi_cost[i * n + j]);
    }
  }

  std::vector<double> slk(n, 0.0);
  std::vector<int> vis_l(n, 0);
  std::vector<int> vis_r(n, 0);
  for (int i = 0; i < n; i++) {
    slk.resize(n, 1e9);
    vis_l.resize(n, 0);
    vis_r.resize(n, 0);

    while (!HavePathKM(i, n, bi_cost, slk, vis_l, vis_r, mark_l, mark_r, pas)) {
      double tmp = 1e9;
      for (int j = 0; j < n; j++) {
        if (!vis_r[j])
          tmp = std::min(tmp, slk[j]);
      }
      for (int j = 0; j < n; j++) {
        if (vis_l[j])
          mark_l[j] += tmp;
      }
      for (int j = 0; j < n; j++) {
        if (vis_r[j])
          mark_r[j] -= tmp;
      }
      for (int j = 0; j < n; j++) {
        slk[j] = 1e9;
        vis_r[j] = 0;
      }
    }
  }
}

}