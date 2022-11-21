class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int j = 0, k = s.size();
        for(int i=0; j < k && i<t.size();i++){
            
            if(s[j] == t[i]){
                j++;
            }        
        }
        if(k == j){
            return true;
        }
            return false;        
    }
};