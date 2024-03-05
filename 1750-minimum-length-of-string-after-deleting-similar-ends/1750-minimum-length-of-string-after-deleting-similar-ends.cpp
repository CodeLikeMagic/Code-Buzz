class Solution {
public:
    int minimumLength(string s) {
        
        int begin = 0;
        int end = s.size() - 1;
        
        while(begin < end && s[begin] == s[end]){
            
            char c = s[begin];
            
            //deleting prefix
            while(begin <= end && s[begin] == c){
                begin++;
            }
            
            //deleting suffix
            while(end > begin && s[end] == c){
                end--;
            }
        }
        
        return end - begin + 1;
    }
};