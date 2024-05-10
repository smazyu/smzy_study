'''
你在一个城市里，城市由 n 个路口组成，路口编号为 0 到 n - 1 ，某些路口之间有 双向 道路。输入保证你可以从任意路口出发到达其他任意路口，且任意两个路口之间最多有一条路。

给你一个整数 n 和二维整数数组 roads ，其中 roads[i] = [ui, vi, timei] 表示在路口 ui 和 vi 之间有一条需要花费 timei 时间才能通过的道路。你想知道花费 最少时间 从路口 0 出发到达路口 n - 1 的方案数。

请返回花费 最少时间 到达目的地的 路径数目 。由于答案可能很大，将结果对 109 + 7 取余 后返回。
'''


'''
戴克斯特拉算法（Dijkstra's algorithm）是一种用于找出加权图中的最短路径的贪心算法。它是由荷兰计算机科学家艾兹赫尔·戴克斯特拉在1956年提出的。
Dijkstra算法
算法步骤
初始化：将所有节点的最短距离估计值初始化为无穷大，除了源节点，其距离初始化为0。设置一个空集合来存储已经处理过的节点。

选择最小距离节点：从尚未处理的节点集合中选出距离源点最近的节点，我们称之为当前节点。

更新邻接节点距离：对于当前节点的每一个未处理的邻接节点，检查是否可以通过当前节点到达它的距离小于已知的最短距离。如果可以，更新这个邻接节点的最短距离。

标记为已处理：当前节点被标记为已处理，意味着其最短距离已经被找到并且不会再被更新。

重复步骤2-4：重复步骤2到4，直到所有的节点都被处理过。

'''
'''import heapq

# 创建图
graph = {
    0: [(1, 4), (2, 2)],
    1: [(2, 3)],
    2: [(1, 3)]
}

def dijkstra(graph, start):
    # 初始化距离字典，所有节点的距离都设为无穷大，除了起点
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    
    # 创建优先队列，并把起点入队
    pq = [(0, start)]
    
    while pq:
        # 弹出最小距离的节点
        current_distance, current_node = heapq.heappop(pq)
        
        # 如果当前节点的距离大于字典中记录的距离，则跳过
        if current_distance > distances[current_node]:
            continue
        
        # 查看当前节点的邻接节点
        for neighbor, weight in graph[current_node]:
            distance = current_distance + weight
            
            # 如果找到更短的路径，则更新该节点的距离并将其加入优先队列
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))
                
    return distances

# 计算从节点0到所有节点的最短路径
distances = dijkstra(graph, 0)
print(distances)
'''

graph = {
    0: [(1, 4), (2, 2)],
    1: [(2, 3)],
    2: [(1, 3)]
}
from typing import List
def countPaths( n: int, roads: List[List[int]]) -> int:
    graph = {i: [] for i in range(n)}
    for a, b, t in roads:
        graph[a].append((b, t))
        graph[b].append((a, t))

    # print(graph)
# countPaths(7,[[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]])






















