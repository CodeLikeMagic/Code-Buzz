class Solution {
public:
    
    bool canConstruct(string ransomNote, string magazine) {
       
        int freq[26] = {0};
        char c;
        
        for(int i=0; i<magazine.size(); i++){
            
            c = magazine[i];
            freq[c - 97]++;
        }
        
        for(int i=0; i<ransomNote.size(); i++){
            
            c = ransomNote[i];
            if(freq[c - 97]){
                freq[c - 97]--;
            }else{
                return false;
            }
        }
        return true;        
    }
};