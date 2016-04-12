#include <vector>
#include <cstdio>

using namespace std;

typedef vector<int> vi;

void backtrack(vi &path, bool &none, const vi &xs, const int pos, const int target)
{
    if (target == 0) {
        none = false;
        printf("%d", path[0]);
        for (int i = 1; i < path.size(); ++i) {
            printf("+%d", path[i]);
        }
        puts("");
        return;
    }
    if (target < 0 || pos >= xs.size()) {
        return;
    }
    
    int end = pos;
    while (end < xs.size() && xs[end] == xs[pos]) {
        end++;
    }
    for (int i = end-1; i >= pos; --i) {
        for (int j = pos; j <= i; ++j) {
            path.push_back(xs[i]);    
        }
        backtrack(path, none, xs, end, target-xs[pos]*(i-pos+1));
        for (int j = pos; j <= i; ++j) {
            path.pop_back();
        }
    } 
    backtrack(path, none, xs, end, target);
}

int main()
{
    int t,n;
    while (scanf("%d %d", &t, &n) != EOF && (t != 0 && n != 0)) {
        vi xs(n, 0);
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            xs[i] = x;
        }
        printf("Sums of %d:\n", t);
        
        vi path;
        bool none = true;
        backtrack(path, none, xs, 0, t);
        if (none) {
            puts("NONE");
        }
    }
}