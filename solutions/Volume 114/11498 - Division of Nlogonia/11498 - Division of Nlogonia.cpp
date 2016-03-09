#include <cstdio>

using namespace std;

int main()
{
    int T = 0;
    while (scanf("%d", &T) != EOF && T) {
        int x0 = 0;
        int y0 = 0;
        scanf("%d %d", &x0, &y0);
        for (int i = 0; i < T; ++i) {
            int x = 0;
            int y = 0;
            scanf("%d %d", &x, &y);
            const char *s = "";
            if (x == x0 || y == y0) {
                s = "divisa";    
            } else if (x < x0 && y < y0) {
                s = "SO";
            } else if (x > x0 && y < y0) {
                s = "SE";
            } else if (x > x0 && y > y0) {
                s = "NE";
            } else {
                s = "NO";
            }
            puts(s);
        }
    }
}