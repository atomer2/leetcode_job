// solution learn from others
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.empty() && s2.empty())
            return true;
        char count[256] = {0};
        for(const auto& e: s1){
            count[e]++;
        }
        for(const auto& e: s2){
            count[e]--;
        }
        for(int i=0; i< 256; i++){
            if(count[i] != 0)
                return false;
        }
        int len = s1.size();
        // pruning
        if(len <= 3)
            return true;
        for(int i=1; i<len; ++i){
           if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                isScramble(s1.substr(i, len-i), s2.substr(i, len-i))) ||
               (isScramble(s1.substr(0, i), s2.substr(len-i,i)) &&
                isScramble(s1.substr(i, len-i), s2.substr(0, len-i))))
               return true;
        }
        return false;      
    }
};
