#include <cstdio>
#include <vector>

using namespace std;

typedef vector<long long> vll;

void dfs(int &count, const long long sum_, vll &nums, const int start, const int cur, const long long size, const long long d)
{
    if (cur == size) {
        if (sum_ % d ==0) {
            count++;
        }
    }
    
    for (int i = start; i < nums.size(); ++i) {
        dfs(count, sum_+nums[i], nums, i+1, cur+1, size, d);
    }
}

int main()
{
    int N, Q;
    int setn = 1;
    while (scanf("%d %d", &N, &Q) && (N != 0 && Q != 0)) {
        vll v(N, 0);
        for (int i = 0; i < N; ++i) {
            long long num;
            scanf("%lld", &num);
            v[i] = num;
        }
        
        printf("SET %d:\n", setn++);
        for (int i = 1; i <= Q; ++i) {
            long long D, M;
            scanf("%lld %lld", &D, &M);
            int count = 0;
            dfs(count, 0, v, 0, 0, M, D);
            printf("QUERY %d: %d\n", i, count);
        }
    }
}