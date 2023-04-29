class Solution {
public:
    int countDigits(int num) {
        
        int digits = num;
        int n=0, count = 0;
        
        while(digits != 0){
                   
            n = digits%10;
            if(num%n == 0){
                count++;
            }
                
            digits = digits/10;
        }
        return count;
    }
};