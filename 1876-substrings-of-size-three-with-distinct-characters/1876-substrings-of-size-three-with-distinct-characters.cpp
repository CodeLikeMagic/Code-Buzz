class Solution {
public:
    int countGoodSubstrings(string s) {
        
        map<char,int> mp;
        int distinct = 0,answer = 0;
        
        for(int i=0, j=0; i<s.size();i++){
            
            if(i < 3){
                char c = s[i];
                mp[c]++;                
            }
            else{
                distinct = mp.size();
                cout<<"d "<<distinct<<endl;
                if(distinct == 3){
                    answer++;
                }
                char c = s[j];
                mp[c]--; //remove previous
                if(mp[c] == 0){
                    mp.erase(c);
                }
                j++;
                c = s[i];
                mp[c]++; ///slide
            }
        }
        if(mp.size() == 3){
            answer++;
        }
        return answer;
    }
};