// Manacher method O(n)
class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    string s2;
    s2.resize(n * 2 + 1);
    s2[0] = '#';
    for (int i = 0; i < n; i++) {
      s2[2 * i + 1] = s[i];
      s2[2 * i + 2] = '#';
    }

    vector<int> radius(s2.size(), 0);
    int pR = 0;
    int pIndex = -1;
    int maxRadius = INT_MIN;
    int maxCenter = -1;
    for (int i = 0; i < s2.size(); i++) {
      int sym = 2 * pIndex - i;
      if (i < pR && sym - radius[sym] != pIndex - radius[pIndex]) {
        radius[i] = min(radius[sym], sym - pIndex + radius[pIndex]);
      } else {
        int l = i, r = i, rd = 0;
        while (l >= 0 && r < s2.size() && s2[l--] == s2[r++])
          rd++;
        pR = i + rd;
        pIndex = i;
        radius[i] = rd;
      }
      if (radius[i] > maxRadius) {
        maxRadius = radius[i];
        maxCenter = i;
      }
    }
    string res;

    for (int i = maxCenter - maxRadius + 1; i < maxCenter + maxRadius; i++) {
      if (s2[i] != '#')
        res.push_back(s2[i]);
    }
    return res;
  }
};
