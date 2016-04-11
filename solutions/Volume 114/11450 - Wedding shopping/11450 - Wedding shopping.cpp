#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int money, type;
        scanf("%d %d", &money, &type);
        vector<vector<int>> v(type+1, vector<int>(money+1, -1));
        for (int m = 0; m <= money; ++m) {
            v[0][m] = 0;
        }
        for (int i = 1; i <= type; ++i) {
            int count;
            scanf("%d", &count);
            vector<int> costs(count, 0);
            for(int j = 0; j < count; ++j) {
                int cost;
                scanf("%d", &cost);
                costs[j] = cost;
            }
            
            for (int m = 1; m <= money; ++m) {
                for (int j = 0; j < count; ++j) {
                    if (m >= costs[j] && v[i-1][m-costs[j]] != -1) {
                        v[i][m] = max(v[i][m], costs[j] + v[i-1][m-costs[j]]);
                    }
                }
            }
        }
        if (v[type][money] != -1) {
            printf("%d\n", v[type][money]);
        } else {
            puts("no solution");
        }
    }
}