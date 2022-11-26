class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        priority_queue<pair<int,string>> ss;
        vector<string> pp;
        
        int i=0;
        for(auto x : heights){
            
            ss.push({x, names[i]});
            i++;           

        }
        
        while(ss.empty() == false){
            auto p = ss.top();
            pp.push_back(p.second);
            ss.pop();
        }        
        
        return pp;
    }
};