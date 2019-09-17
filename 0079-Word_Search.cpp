// backtrace
class Solution {
    public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> flags;
        for (int i = 0; i < board.size(); ++i) {
            vector<int> b; 
            for (int j = 0; j < board[0].size(); ++j) {
                b.push_back(0);
            }
            flags.push_back(b);
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (backtrace(board, flags, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }



    bool backtrace(vector<vector<char>>& board,
                   vector<vector<int>>& flags,
                   string& word,
                   int pos,
                   int m,
                   int n) {
        if (pos == word.size())
            return true;

        if(m<0 || m>= board.size() || n<0 || n>=board[0].size())
            return false;

        if (flags[m][n] || board[m][n] != word[pos])
            return false;

        flags[m][n] = 1;
        pos++;

        if(backtrace(board, flags, word, pos, m - 1, n)) return true;
        if(backtrace(board, flags, word, pos, m, n - 1)) return true;
        if(backtrace(board, flags, word, pos, m + 1, n)) return true;
        if(backtrace(board, flags, word, pos, m, n + 1)) return true;

        flags[m][n] = 0;
        return false;
    }
};
