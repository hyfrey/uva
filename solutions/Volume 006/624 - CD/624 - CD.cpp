#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

// f[i,n] = max(f[i-1, n-v[i]]+v[i], f[i-1, n])
// f[i,n] = max(f[i+1, n-v[i]]+v[i], f[i+1, n])

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

/*
int dp(const vi &v, int i, int n)
{
    if (i >= v.size()) {
        return n;
    }
    
    if (n >= v[i]) {
        int left = dp(v, i+1, n-v[i]) + v[i];
        int right = dp(v, i+1, n);
        if (left > right) {
            return left;
        } else {
            return right;
        }
    }
    return dp(v, i+1, n);
}
*/

void printpath(const vi &v, const vvi &f, vi &path, const int i, const int n)
{
    if (i <= 0) {
        return;
    }
    
    if (n >= v[i-1] && f[i][n] == f[i-1][n-v[i-1]]+v[i-1]) {
        path.push_back(v[i-1]);
        printpath(v, f, path, i-1, n-v[i-1]);
    } else {
        printpath(v, f, path, i-1, n);
    }
}

// f[i,n] = max(f[i-1, n-v[i]]+v[i], f[i-1, n])
void dp(const vi &v, const int target)
{
    vvi f(v.size()+1, vector<int>(target+1, 0));
    
    for (int i = 0; i < v.size(); ++i) {
        for (int n = 0; n <= target; ++n) {
            if (n >= v[i]) {
                f[i+1][n] = max(f[i][n-v[i]] + v[i], f[i][n]);
            } else {
                f[i+1][n] = f[i][n];
            }
        }
    }
    vi path;
    printpath(v, f, path, v.size(), target);
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); ++i) {
        printf("%d ", path[i]);
    }
    printf("sum:%d\n", f[v.size()][target]);
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
        dp(v, N);
    }
}