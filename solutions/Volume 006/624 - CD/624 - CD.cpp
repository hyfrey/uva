#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef pair<vi, int> pvii;

// f[i,n] = max(f[i-1, n-v[i]]+v[i], f[i-1, n])
// f[i,n] = max(f[i+1, n+v[i]], f[i+1, n])

/*
int dp(vi &v, int i, int n)
{
    if (i < 0 || n <= 0) {
        return 0;
    }
    if (n-v[i] >= 0) {
        return max(dp(v, i-1, n-v[i])+v[i], dp(v, i-1, n));
    }
    return dp(v, i-1, n);
}*/

int dp(vi &v, int i, int n, const int target)
{
    if (i >= v.size()) {
        return n;
    }
    
    if (n+v[i] <= target) {
        return max(dp(v, i+1, n+v[i], target), dp(v, i+1, n, target));
    }
    return dp(v, i+1, n, target);
}

int main()
{
    int N, T;
    while (scanf("%d %d", &N, &T) != EOF) {
        vector<int> v(T, 0);
        for (int i = 0; i < T; ++i) {
            int l;
            scanf("%d", &l);
            v[i] = l;
        }
        printf("%d\n", dp(v, 0, 0, N));
    }
}