class Solution {
public:
   bool topSort(vector<int> adj[], int V){
        
        vector<int> in_degree(V, 0);
        
        for(int u=0; u<V; u++){
            for(int x : adj[u]){
                in_degree[x]++;
            }
        }///calculate indegree
        
        queue<int> q;
        //add ones with 0 indegree
        for(int i=0; i<V; i++){
            if(in_degree[i] == 0){
                q.push(i);
            }
        }
        
        int count = 0; //count for detecting cycle
        //visit adjs and update indegrees
        while(q.empty() == false){
            int u = q.front();
            q.pop();
            count++;
            
            //visit its adjs
            for(int x : adj[u]){
                if(--in_degree[x] == 0){
                    q.push(x);
                }
            }
        }
        return !(count != V);
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        //array of vectors
        vector<int> adj[numCourses];
        
        
        for(auto v : prerequisites){
            vector<int> it = v;
            
            adj[it[0]].push_back(it[1]);    //add connections
        }
        
        return topSort(adj, numCourses);
    }
};