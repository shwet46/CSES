import heapq

INF = 10**18

def dijkstra(n, adj):
    dist = [INF] * (n + 1)
    dist[1] = 0

    pq = [(0, 1)]  # (distance, node)

    while pq:
        d, u = heapq.heappop(pq)

        if d > dist[u]:
            continue

        for v, w in adj[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                heapq.heappush(pq, (dist[v], v))

    return dist


def main():
    n, m = map(int, input().split())
    adj = [[] for _ in range(n + 1)]

    for _ in range(m):
        a, b, c = map(int, input().split())
        adj[a].append((b, c))

    dist = dijkstra(n, adj)

    print(" ".join(str(dist[i]) for i in range(1, n + 1)))


if __name__ == "__main__":
    main()