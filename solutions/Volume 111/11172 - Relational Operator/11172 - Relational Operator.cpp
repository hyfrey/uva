#include <cstdio>

int main()
{
    int T = 0;
    int a = 0;
    int b = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &a, &b);
        char c = ' ';
        if (a < b) {
            c = '<';
        } else if (a > b) {
            c = '>';
        } else {
            c = '=';
        }
        printf("%c\n", c);
    }
}
