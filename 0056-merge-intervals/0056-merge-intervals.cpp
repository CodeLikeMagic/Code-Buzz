class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> v;
        stack<pair<int,int>> s;
        
        sort(intervals.begin(), intervals.end());
        
        s.push({intervals[0][0],intervals[0][1]});
       
        for(int i=1; i<intervals.size(); i++){
            
            int nstart = intervals[i][0];
            int nend = intervals[i][1];
            
            auto pop = s.top();
            s.pop();
            
            int start = pop.first;
            int end = pop.second;
            
            if(nstart <= end){  //next start is lesss than end of prev merge
                if(nend > end){ //if end greater merge end update value
                    s.push({start, nend});
                }
                else{   
                    s.push({start, end});
                }
            }else{  //push both
                s.push(pop);
                s.push({intervals[i][0],intervals[i][1]});
            }
        }
        
        int ss = s.size();
        cout<<ss<<endl;
        
        while(ss--){
            auto pp = s.top();
            s.pop();
            v.push_back({pp.first, pp.second});
        }
        
        reverse(v.begin(), v.end());
        return v;
    }
};