#include <cstdio>
#include <vector>

using namespace std;

// dp[i, m] = dp[i+1, m] + dp[i, m-coins[i]]

int main()
{
    vector<int> coins{1, 5, 10, 25, 50};
    
    int money = 7489;
    vector<vector<int>> dp(6, vector<int>(money+1, 0));
    for (int i = 0; i < 5; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 4; i >= 0; --i) {
        for (int m = 1; m <= money; ++m) {
            if (m >= coins[i]) {
                dp[i][m] = dp[i+1][m] + dp[i][m-coins[i]];
            } else {
                dp[i][m] = dp[i+1][m];
            }
        }
    }

    while (scanf("%d", &money) != EOF) {
        printf("%d\n", dp[0][money]);
    }
}