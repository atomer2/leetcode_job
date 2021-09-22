#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  struct node {
    unordered_map<string, double> edges;
    bool touched = false;
  };

  bool dfs(unordered_map<string, node>& map,
           const string& from,
           const string& to,
           double& d) {
    if (from == to) {
      d = 1.0;
      return true;
    }

    auto& node = map[from];

    if (node.touched) {
      d = -1.0;
      return false;
    }

    node.touched = true;
    for (auto e : node.edges) {
      double dd;

      bool ret = dfs(map, e.first, to, dd);

      if (ret) {
        d = dd * e.second;
        node.touched = false;
        return true;
      }
    }
    node.touched = false;

    d = -1.0;
    return false;
  }

  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    vector<double> ret;
    unordered_map<string, node> map;
    for (int i = 0; i < equations.size(); i++) {
      auto& p = equations[i];
      map[p[0]].edges.insert({p[1], values[i]});
      map[p[1]].edges.insert({p[0], 1.0 / values[i]});
    }

    for (auto& e : queries) {
      if (!map.count(e[0])) {
        ret.push_back(-1.0);
      } else {
        double r = 1.0;
        dfs(map, e[0], e[1], r);
        ret.push_back(r);
      }
    }
    return ret;
  }
};

int main(int argc, char** argv) {
  return 0;
}
