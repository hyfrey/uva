#include <cstdio>
#include <algorithm>

using namespace std;

inline int _mid(int a, int b, int c)
{
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);

    return b;
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        printf("Case %d: %d\n", i, _mid(a, b, c));
    }
}