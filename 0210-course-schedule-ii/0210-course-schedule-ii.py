class Solution:
    def add_edge(self, adj, i, j):
        adj[i].append(j) if j not in adj[i] else None
    
    def topological_bfs(self, V, adj):
        indegree = [0] * V
        for i in range(V):
            for nbr in adj[i]:
                indegree[nbr] += 1

        q = deque()     #fetching nodes with zero value
        for i in range(V):
            if indegree[i] == 0:
                q.append(i)

        topo_order = []
        while q:
            node = q.popleft()
            topo_order.append(node)
            for nbr in adj[node]:   #remove dependency of this node on nbrs
                indegree[nbr] -= 1
                if indegree[nbr] == 0:
                    q.append(nbr)

        return topo_order
    
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(numCourses)]
        for c in prerequisites:
            post, pre = c[0], c[1]
            self.add_edge(adj, pre, post)

        result = self.topological_bfs(numCourses, adj)
        if len(result) != numCourses:
            return []
        else:
            return result