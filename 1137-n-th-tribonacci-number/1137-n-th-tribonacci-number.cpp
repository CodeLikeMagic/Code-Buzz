class Solution {
public:
    unsigned long long int fibs[50] = {0};
    int tribonacci(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 1;
        }
        if(fibs[n]){
            return fibs[n];
        }
        return fibs[n] = tribonacci(n-1)
            +
            tribonacci(n-2)
            +
            tribonacci(n-3);
    }
};