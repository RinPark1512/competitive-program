from collections import deque, defaultdict

n, m, d = map(int, input().split())
skepticism = {}
for _ in range(n):
    line = input().split()
    skepticism[line[0]] = int(line[1])
graph = defaultdict(list)
for _ in range(m):
    line = input().split()
    graph[line[0]].append(line[1])
    graph[line[1]].append(line[0])
start = input()

def bfs(graph, start):
    global skepticism
    global day_heard
    day_heard[start] = 0
    queue = deque([start])

    while queue:
        node = queue.popleft()
        if skepticism[node] == 0:
            for neighbor in graph[node]:
                if skepticism[neighbor] > 0:
                    queue.append(neighbor)
                    day_heard[neighbor] = day_heard[node] + 1
                    skepticism[neighbor] -= 1


day_heard = {}
bfs(graph, start)
count = -1
for person, day in day_heard.items():
    if day <= d:
        count += 1

print(count)