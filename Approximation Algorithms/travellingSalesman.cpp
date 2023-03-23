#include <bits/stdc++.h>
using namespace std;

int dp[1024][10];

int travellingSalesman(int mask, int pos, int &n, vector<vector<int>> &cost,
                       int &visitedAll) {

  if (mask == visitedAll) {
    return cost[pos][0];
  }

  if (dp[mask][pos] != -1)
    return dp[mask][pos];

  int ans = INT_MAX;
  for (int city = 0; city < n; city++) {
    int temp_mask = (1 << city);
    if (!(temp_mask & mask)) {
      int newAns = cost[pos][city] + travellingSalesman(mask | temp_mask, city,
                                                        n, cost, visitedAll);
      ans = min(ans, newAns);
    }
  }

  return dp[mask][pos] = ans;
}
int total_cost(vector<vector<int>> &cost) {

  int n = cost.size(), visitedAll = (1 << n) - 1;
  memset(dp, -1, sizeof dp);

  return travellingSalesman(1, 0, n, cost, visitedAll);
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> cost(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> cost[i][j];
    }
  }
  int ans = total_cost(cost);
  cout << "Total Cost of TSP:" << ans;
  return 0;
}
