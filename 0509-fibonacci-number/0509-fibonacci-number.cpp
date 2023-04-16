class Solution {
public:
    
    unsigned long long int fibs[50] = {0};
    int fib(int n) {
        
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        if(fibs[n]){
            return fibs[n];
        }
        return fibs[n] = fib(n-1)+fib(n-2);
    }
};