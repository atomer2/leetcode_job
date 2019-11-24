class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() == 0 || prices.size() == 1)
      return 0;
    int res = 0;
    int bottom = prices[0];
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] <= bottom)
        bottom = prices[i];
      else if (i + 1 >= prices.size() || prices[i + 1] < prices[i]) {
        res += prices[i] - bottom;
        bottom = prices[i];
      }
    }
    return res;
  }
};

