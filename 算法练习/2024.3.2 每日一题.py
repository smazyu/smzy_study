'''
无向树：无向树是一种特殊的图，它是由边连接的节点的集合，没有方向，且任意两个节点间有且仅有一条路径。由于是无向的，
所以从任一节点到另一节点都是可达的，除非特别指定某些节点不可达（即受限节点）

'''
from collections import deque
from typing import List
'''
深度优先搜索（DFS）
def dfs(graph, node, visited):
    if node not in visited:
        print(node, end=' ')
        visited.add(node)
        for neighbour in graph[node]:
            dfs(graph, neighbour, visited)

# 示例图的邻接列表表示
graph = {
    'A' : ['B','C'],
    'B' : ['D', 'E'],
    'C' : ['F'],
    'D' : [],
    'E' : ['F'],
    'F' : []
}

visited = set()  # 用于跟踪访问过的节点
dfs(graph, 'A', visited)  # 从节点 'A' 开始DFS
广度优先搜索（BFS）
from collections import deque

def bfs(graph, start):
    visited = set()  # 记录访问过的节点
    queue = deque([start])  # 使用队列支持BFS的层次遍历

    while queue:
        vertex = queue.popleft()  # 从队列中取出当前节点
        if vertex not in visited:
            print(vertex, end=' ')
            visited.add(vertex)  # 标记为已访问
            # 将所有未访问的邻接节点添加到队列中
            for neighbor in graph[vertex]:
                if neighbor not in visited:
                    queue.append(neighbor)

# 示例图的邻接列表表示
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E'],
}

bfs(graph, 'A')
'''

#深度优先搜索（DFS）
class Solution:
    def reachableNodes(self, n: int, edges: List[List[int]], restricted: List[int]) -> int:
        # 构建图的邻接列表
        graph = {i: [] for i in range(n)}
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)

        visited = [False] * n  # 跟踪访问状态
        restrictedSet = set(restricted)  # 将受限节点转换为集合以加快查找速度

        def dfs(node):
            if visited[node] or node in restrictedSet:  # 如果节点已访问或受限，则不继续
                return 0
            visited[node] = True  # 标记为已访问
            total = 1  # 当前节点也计入总数
            for neighbor in graph[node]:
                if not visited[neighbor] and neighbor not in restrictedSet:
                    total += dfs(neighbor)  # 递归访问邻居
            return total
        return dfs(0)  # 从节点 0 开始深度优先搜索class Solution:
#广度优先搜索（BFS）
class Solution:
        def reachableNodes(self, n: int, edges: List[List[int]], restricted: List[int]) -> int:
            children = [[] for _ in range(n)]
            for n1, n2 in edges:
                children[n1].append(n2)
                children[n2].append(n1)
            visited = [False for _ in range(n)]
            for i in restricted:
                visited[i] = True

            explore = deque([0])
            ans = 0
            while explore:
                node = explore.popleft()
                ans += 1
                visited[node] = True
                for child in children[node]:
                    if visited[child]:
                        continue
                    explore.append(child)
            return ans
