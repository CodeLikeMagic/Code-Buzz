class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman;
        unordered_map<char, int> prio;
        
        roman.insert({'I',1});
        roman.insert({'V',5});
        roman.insert({'X',10});
        roman.insert({'L',50});
        roman.insert({'C',100});
        roman.insert({'D',500});
        roman.insert({'M',1000});
        
        prio.insert({'I',1});
        prio.insert({'V',2});
        prio.insert({'X',3});
        prio.insert({'L',4});
        prio.insert({'C',5});
        prio.insert({'D',6});
        prio.insert({'M',7});
        
        int result = 0;
        result = roman[s[s.size()-1]];
        
        for(int i=s.size()-2; i>=0; i--){
            
            if(prio[s[i]] < prio[s[i+1]]){
                result -= roman[s[i]];
            }else{
                result += roman[s[i]];
            }            
        }
        
        cout<<result;
        return result;
    }
};