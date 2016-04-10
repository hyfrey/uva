#include <cmath>
#include <cstdio>

int main()
{
    int N;
    while (scanf("%d", &N) != EOF) {
        int step = (int)log2(N) + 1;
        printf("%d\n", step);
    }
}