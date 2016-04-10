#include <cstdio>
#include <vector>

using namespace std;

enum { M = 120 };

int main()
{
    int n;
    while (scanf("%d", &n) && n != 0) {
        vector<int> v(M, 0);
        for (int i = 0; i < n; ++i) {
            int age;
            scanf("%d", &age);
            v[age]++;
        }
        bool first = true;
        for (int age = 1; age < v.size(); ++age) {
            for (int j = 0; j < v[age]; ++j) {
                if (!first) {
                    printf(" ");
                }
                first = false;
                printf("%d", age);
            }
        }
        puts("");
    }
}