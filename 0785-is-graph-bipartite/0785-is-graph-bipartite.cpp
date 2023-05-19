class Solution {
public:
   bool dfs_helper(vector<vector<int>>& graph, int node, vector<int> &visited, int parent, int color){
        
        if(visited[node] == 0)
            visited[node] = color;  //1 or 2
        for(auto nbr : graph[node]){ //visit all nbr
         
            if(visited[nbr] == 0){
                bool subprob = dfs_helper(graph, nbr, visited, node, 3-color);
                
                if(subprob == false){
                    return false;
                }
            }
            else if(nbr != parent && color == visited[nbr]){
                return false;
            }
        }
        
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph){
        
        int N = graph.size();
        vector<int> visited(N, 0);
        int color = 1;
        
        bool response = false;
        for(int i=0; i<graph.size(); i++){
            
            if(visited[i] == 0){
                
                response = dfs_helper(graph, i, visited, -1, color);
                if(response == false){
                    return response;
                }
            }
        }
        return response;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        return dfs(graph);
    }
};