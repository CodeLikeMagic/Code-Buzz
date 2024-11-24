class Solution:
    def __init__(self):
        self.timer = 1

    def dfs(self, node, parent, vis, adj, tin, low, bridges):
        vis[node] = True
        tin[node] = low[node] = self.timer
        self.timer += 1

        for nbr in adj[node]:
            if nbr == parent:
                continue
            if not vis[nbr]:
                self.dfs(nbr, node, vis, adj, tin, low, bridges)
                low[node] = min(low[node], low[nbr])
                #check for all the edges for - bridge edge
                if low[nbr] > tin[node]:
                    bridges.append([node, nbr])
            else:
                low[node] = min(low[node], tin[nbr])

    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        adj = [[] for _ in range(n)]
        for u, v in connections:
            adj[u].append(v)
            adj[v].append(u)

        print(adj)
        vis = [False] * n
        tin = [-1] * n
        low = [-1] * n
        bridges = []

        #starting dfs from 0
        self.dfs(0, -1, vis, adj, tin, low, bridges)

        return bridges