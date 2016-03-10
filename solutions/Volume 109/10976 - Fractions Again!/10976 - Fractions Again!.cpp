#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
    int k;
    while (scanf("%d", &k) != EOF) {
        vii v;
        for (int y = k+1; y <= 2*k; y++) {
            if ((k*y)%(y-k) == 0) {
                int x = (k*y)/(y-k);
                v.push_back(make_pair(x,y));
            }
        }
        printf("%d\n", v.size());
        for (int i = 0; i < v.size(); ++i) {
            printf("1/%d = 1/%d + 1/%d\n", k, v[i].first, v[i].second);
        }
    }
}