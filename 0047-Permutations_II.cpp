
// Basically, assume we have "1234", the idea is to increase the number in ascending order, so next is "1243", next is "1324", and so on. Actuallly, it's a problem similar to "Next Permuation".

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &S) {
        // res.clear();
        sort(S.begin(), S.end());        
        res.push_back(S);
        int j;
        int i = S.size()-1;
        while (1){
            for (i=S.size()-1; i>0; i--){
                if (S[i-1]< S[i]){
                    break;
                }
            }
            if(i == 0){
                break;
            }

            for (j=S.size()-1; j>i-1; j--){
                if (S[j]>S[i-1]){
                    break;
                }
            }                    
            swap(S[i-1], S[j]);
            reverse(S, i, S.size()-1);
            res.push_back(S);
        }
        return res;
    }
    void reverse(vector<int> &S, int s, int e){        
        while (s<e){
            swap(S[s++], S[e--]);
        }
    }

    vector<vector<int> > res;
};
