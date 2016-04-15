#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

void backtrack(const vector<int> &xs, string &ops, const int y, bool &can, const int target, int pos)
{
    if (can) {
        return;
    }
    
    if (pos == xs.size()) {
        can = (y == target);
        #ifdef _DEBUG
        if (y == target) {
            printf("%d ", xs[0]);
            for (int i = 1; i < xs.size(); ++i) {
                printf(" %c %d", ops[i], xs[i]);
            }
            printf(" = %d\n", y);
        }
        #endif
        return;
    }
    
    ops[pos] = '+';
    backtrack(xs, ops, y+xs[pos], can, target, pos+1);
    ops[pos] = '-';
    backtrack(xs, ops, y-xs[pos], can, target, pos+1);
    ops[pos] = '*';
    backtrack(xs, ops, y*xs[pos], can, target, pos+1);
}

int main()
{
    int a,b,c,d,e;
    int target = 23;
    while (scanf("%d %d %d %d %d", &a, &b, &c, &d, &e) != EOF) {
        if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0) {
            return 0;
        }
        
        vector<int> xs{a, b, c, d, e};
        string ops = "#####";
        bool can = false;
        sort(xs.begin(), xs.end());
        do {
            int y = xs[0];
            backtrack(xs, ops, y, can, target, 1);
            if (can) {
                break;
            }
        } while (next_permutation(xs.begin(), xs.end()));
        puts(can ? "Possible" : "Impossible");
    }
}