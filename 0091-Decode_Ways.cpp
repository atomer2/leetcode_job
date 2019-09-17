class Solution { 
    public:
    int numDecodings(string s) { 
        vector<long long> table(s.size()+1, 0);
        table.back() = 1; 
        for (int i = s.size() - 1; i >= 0; i--) { 
            if(s[i] != '0'){
                int res = table[i+1];    
                if (i + 2 < table.size() && ((s[i] == '2' && s[i + 1] <= '6') || (s[i] == '1'))) { 
                    res += table[i + 2];
                } 
                table[i] = res;            
            }            
        }
        return table[0];
    } 

};
