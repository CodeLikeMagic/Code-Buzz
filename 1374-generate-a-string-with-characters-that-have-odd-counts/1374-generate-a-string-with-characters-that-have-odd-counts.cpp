class Solution {
public:
    string generateTheString(int n) {
        string str;
            
        if(n%2 != 0){
            while(n--){
                str.push_back('a');
            }
            
        }else{
            int num = n-1;
            while(num--){
                str.push_back('a');
            }
            str.push_back('b');
        }
        return str;
    }
};