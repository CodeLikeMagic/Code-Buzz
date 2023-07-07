class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxSize = k;
        
        unordered_map<char, int> fq;
        
        for(int i=0; i<k; i++){
            fq[answerKey[i]]++;
        }
        
        int left = 0;
        
        for(int right=k; right < answerKey.length(); right++){
            
            fq[answerKey[right]]++;
            
            while(min(fq['T'],fq['F']) > k){
                
                fq[answerKey[left]]--;
                left++;
            }
            
            maxSize = max(maxSize, right-left+1);
        }
                  
        return maxSize;
    }
};