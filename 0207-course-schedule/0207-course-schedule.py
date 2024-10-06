class Solution:
    
    def add_edge(self, adj, i, j):
        adj[i].append(j) if j not in adj[i] else None
    
    def isCyclicBFS(self, V, adj):    #modified Kahn Algorithm
        indegree = [0] * V
        for i in range(V):
            for nbr in adj[i]:
                indegree[nbr] += 1

        q = deque()  # fetching nodes with zero value
        for i in range(V):
            if indegree[i] == 0:
                q.append(i)

        verify_nodes = 0
        while q:
            node = q.popleft()
            verify_nodes += 1
            for nbr in adj[node]:  # remove dependency of this node on nbrs
                indegree[nbr] -= 1
                if indegree[nbr] == 0:
                    q.append(nbr)

        if verify_nodes == V:
            return True
        return False

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = [[] for _ in range(numCourses)]
        for c in prerequisites:
            post, pre = c[0], c[1] 
            self.add_edge(adj, pre, post)
            
        return self.isCyclicBFS(numCourses, adj)