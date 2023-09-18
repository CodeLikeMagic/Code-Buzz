#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
        
        int i = 0, l=-1;
        for(int i=0; i<n; i++){
            l = count(mat[i].begin(), mat[i].end(), 1);
            cout<<l<<endl;
            pq.push({l, i});
        }
        
        vector<int> v;
        while(k--){
            
            v.push_back(pq.top().second);
            pq.pop();
            
        }
        
        return v;
    }
};