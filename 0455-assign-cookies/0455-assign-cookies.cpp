class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.size() == 0 || s.size() == 0){
            return 0;
        }
        
        sort(g.rbegin(), g.rend());
        sort(s.rbegin(), s.rend());
        int c = 0;
               
        for(int i=0, j=0; i<g.size()&&j<s.size();){
            
            if(g[i] <= s[j]){
                c++;
                i++;
                j++;
            }else{
                i++;   
            }
        }
        
        return c;
    }
};