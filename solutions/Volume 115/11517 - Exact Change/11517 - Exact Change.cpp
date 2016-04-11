#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

enum {MAX_VALUE=10000};

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int price;
        scanf("%d", &price);
        int n;
        scanf("%d", &n);
        vector<int> coins(n, 0);
        for (int i = 0; i < n; ++i) {
            int coin;
            scanf("%d", &coin);
            coins[i] = coin;
        }
        
        vector<int> v(price+MAX_VALUE+10, INT_MAX);
        
        v[0] = 0;
        for (int i = 0; i <= price; ++i) {
            if (v[i] != INT_MAX) {
                for (int j = 0; j < coins.size(); ++j) {
                    printf("%d+%d=%d\n", i, coins[j], i+coins[j]);
                    v[i+coins[j]] = min(v[i+coins[j]], v[i]+1);
                }
            }
        }
        
        for (int i = price; i < v.size(); ++i) {
            if (v[i] != INT_MAX) {
                printf("%d %d\n", i, v[i]);
                break;
            }
        }
    }
}