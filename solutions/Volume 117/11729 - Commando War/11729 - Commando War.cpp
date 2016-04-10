#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
    int N = 0;
    int casen = 1;
    while (scanf("%d", &N) != EOF) {
        if (N == 0) {
            return 0;
        }
        
        vii v;
        v.reserve(N);
        for (int i = 0; i < N; ++i) {
            int b,j;
            scanf("%d %d", &b, &j);
            v.push_back(ii(b, j));
        }
        sort(v.begin(), v.end(), [](ii x, ii y) {return x.second > y.second;});
        int start = 0;
        int end = 0;
        for (int i = 0; i < N; ++i) {
            start += v[i].first;
            int newend = start + v[i].second;
            end = max(newend, end);
        }
        printf("Case %d: %d\n", casen++, end);
    }
}