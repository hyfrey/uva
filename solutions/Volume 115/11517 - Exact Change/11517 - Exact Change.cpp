#include <vector>
#include <cstdio>

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
        
        vector<int> v(prices+1, 0);
        int pays = 0;
        int paysn = 0;
        
    }
}