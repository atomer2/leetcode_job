// elegant solution learn from others
// TC O(n)
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() == 0 || prices.size() == 1)
      return 0;
    int maxPro = 0;
    int minPrices = prices[0];
    for (int i = 0; i < prices.size(); ++i) {
      if (prices[i] < minPrices)
        minPrices = prices[i];
      else if (prices[i] - minPrices > maxPro)
        maxPro = prices[i] - minPrices;
    }
    return maxPro;
  }
};

