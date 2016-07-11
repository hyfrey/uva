#include <cstdio>
#include <utility>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

pair<vi, int> dijkstra(vector<vii> &G, const int start, const int end)
{
    vi dist(G.size(), INT_MAX);
    priority_queue<ii, vii, greater<ii>> pq;

    dist[start] = 0;
    pq.push(ii(0, start));
    while (!pq.empty()) {
        ii top = pq.top();
        pq.pop();
        int du = top.first;
        int u = top.second;
        if (dist[u] == du) {
            for (ii &e : G[u]) {
                int v = e.first;
                int d = e.second;
                if (dist[u] + d < dist[v]) {
                    dist[v] = dist[u] + d;
                    pq.push(ii(dist[v], v));
                }
            }
        }
    }
    return pair<vi, int>(vi(), dist[end]);
}

int main()
{
    int N = 0;
    while (scanf("%d", &N) != EOF && N != 0) {
        vector<vii> G(N+1, vii());
        for (int u = 1; u <= N; ++u) {
            int M = 0;
            scanf("%d", &M);
            for (int i = 0; i < M; ++i) {
                int v = 0;
                int d = 0;
                scanf("%d %d", &v, &d);
                G[u].push_back(ii(v, d));
            }
        }
        int start = 0;
        int end = 0;
        scanf("%d %d", &start, &end);
        auto r = dijkstra(G, start, end);
        printf("%d\n", r.second);
    }
}