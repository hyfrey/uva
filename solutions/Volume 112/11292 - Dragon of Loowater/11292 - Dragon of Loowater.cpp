#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int main()
{
    int N, M;
    while (scanf("%d %d", &N, &M) != EOF) {
        if (N == 0 && M == 0) {
            return 0;
        }
        vi ns(N, 0);
        vi ms(M, 0);
        for (int i = 0; i < N; ++i) {
            int n;
            scanf("%d", &n);
            ns[i] = n;
        }
        for (int i = 0; i < M; ++i) {
            int m;
            scanf("%d", &m);
            ms[i] = m;
        }
        if (N <= M) {
            sort(ns.begin(), ns.end());
            sort(ms.begin(), ms.end());
            int i = 0;
            int j = 0;
            int gold = 0;
            while (i < N && j < M) {
                if (ms[j] >= ns[i]) {
                    gold += ms[j];
                    i++;
                    j++;
                } else {
                    j++;
                }
            }
            if (i == N) {
                printf("%d\n", gold);
                continue;
            }
        }
        puts("Loowater is doomed!");
    }
}