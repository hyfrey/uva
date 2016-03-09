#include <vector>
#include <cstdio>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int dp(vvi &M, vi &P, vi &W, int i, int w)
{
    if (i < 0 || w <= 0) {
        return 0;
    }
    
    if (M[i][w] != -1) {
        return M[i][w];
    }
    
    int nt = dp(M, P, W, i-1, w);
    if (W[i] > w) {
        M[i][w] = nt;
    } else {
        M[i][w] = max(nt, dp(M, P, W, i-1, w-W[i]) + P[i]);
    }
    return M[i][w];
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    while (T--) {
        int N = 0;
        scanf("%d", &N);
        vi P(N, 0);
        vi W(N, 0);
        for (int i = 0; i < N; ++i) {
            int p = 0;
            int w = 0;
            scanf("%d %d", &p, &w);
            P[i] = p;
            W[i] = w;
        }

        int G = 0;
        scanf("%d", &G);
        vi GW(G, 0);
        int mw = 0;
        for (int i = 0; i < G; ++i) {
            int w = 0;
            scanf("%d", &w);
            GW[i] = w;
            mw = max(mw, w);
        }
        
        vvi M(N+1, vi(mw+1, -1));
        int sum = 0;
        for (int i = 0; i < GW.size(); ++i) {
            sum += dp(M, P, W, N-1, GW[i]);
        }
        printf("%d\n", sum);
    }
}