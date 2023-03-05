class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int count = 0, temp = 0;
        
        for(int i=0; i<sentences.size(); i++){
            temp = 0;
            for(int j=0; j<sentences[i].size(); j++){
                
                if(sentences[i][j] == ' '){
                    temp++;
                }
            
            }
            count = max(temp+1, count);
        }
        
        return count;
    }
};