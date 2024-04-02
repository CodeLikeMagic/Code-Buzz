class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        
        unordered_map<char, char> mapp;
        unordered_map<char, bool> isUsed;
        
        for(int i=0; i<s.size(); i++){
            
            char ch1 = s[i];
            char ch2 = t[i];
            
            if(mapp[ch1]){
                if(mapp[ch1] != ch2){
                    return false;
                }
            }else{
                if(isUsed[ch2]){
                    return false;
                }else{
                    mapp[ch1] = ch2;
                    isUsed[ch2] = true;
                }
            }            
        }
        return true;
    }
};