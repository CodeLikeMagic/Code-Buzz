class Solution {
public:
    void BFS(vector<vector<int>>& isConnected, int i, bool visited[]){
	
	queue<int> q;
	visited[i] = true;
	q.push(i);
	
	while(q.empty() == false){
		int u = q.front();
		q.pop();
		cout<<u<<" ";
        int index = 0;

        for(int j = 0; j<isConnected[u].size(); j++){
            if(j == u){
                continue;
            }    
            if(visited[j] == false && isConnected[u][j] == 1){
				visited[j] = true;
				q.push(j);
			    }
		    }
        }
    }

   int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int v = isConnected.size();
        bool visited[v+1];

        for(int i=0; i<v; i++){
            visited[i] = false;
        }

        for(int i=0; i<v; i++){
            if(visited[i] == false){
                BFS(isConnected, i, visited);
                count++;	//cc
            }
        }
        return count;	//cc        
    }
};