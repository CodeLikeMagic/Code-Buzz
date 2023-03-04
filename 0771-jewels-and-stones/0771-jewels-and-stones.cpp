class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        int freq[128] = {0};
        
        for(int i=0; i<stones.size(); i++){
            
            char ch = stones[i];
            freq[ch]++;
        }
        
        int count = 0;
        for(int i=0; i<jewels.size(); i++){
            char ch = jewels[i];
            if(freq[ch] > 0){
                count += freq[ch];
                freq[ch] = 0;
            }
        }
        
        return count;
    }
};