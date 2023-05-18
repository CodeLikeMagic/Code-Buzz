class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
         vector<int>ad[n];
        for(auto i:edges){
            ad[i[0]].push_back(i[1]);
        }
      vector<int>ind(n,0);
        for(int i=0;i<n;i++){
            for(auto x:ad[i])ind[x]++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!ind[i])ans.push_back(i);
        }
        return ans;
    }
};