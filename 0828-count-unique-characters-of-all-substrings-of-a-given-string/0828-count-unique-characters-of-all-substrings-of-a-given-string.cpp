class Solution {
public:
    int uniqueLetterString(string s) {
        
        
        int n = s.size();
        vector<vector<int>> hashmap(26);
        
        /////push -1 for all keys in value list
        for(int i=0; i<26; i++){
            hashmap[i].push_back(-1);
        }
        
        ///store all indices
        for(int i=0; i<n; i++){
            hashmap[s[i]-'A'].push_back(i);
        }
        
        ////push length of string for all keys at the end of each value list
        for(int i=0; i<26; ++i){
            hashmap[i].push_back(n);
        }
        
        long long count = 0;
        for(int i=0; i<26; ++i){
            
            for(int j=1; j<hashmap[i].size()-1; ++j){
                count += (hashmap[i][j]-hashmap[i][j-1])*
                        (hashmap[i][j+1]-hashmap[i][j]);
            }            
        }
        return count;
    }
};