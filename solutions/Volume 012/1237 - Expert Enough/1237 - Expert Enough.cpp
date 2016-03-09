#include <string>
#include <cstdio>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<string, int, int> Entry;

void solve()
{
    int D;
    scanf("%d", &D);
    
    vector<Entry> d;
    d.reserve(D);
    while (D--) {
        char s[25];
        int l,h;
        scanf("%s %d %d", s, &l, &h);
        auto entry = make_tuple(string(s), l, h);
        d.push_back(entry);
    }
    
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int p = 0;
        scanf("%d", &p);
        
        int times = 0;
        int index = 0;
        for (int i = 0; i < d.size(); ++i) {
            const int l = get<1>(d[i]);
            const int h = get<2>(d[i]);
            if (p >= l && p <= h) {
                times++;
                index = i;
            }
        }
        if (times == 1) {
            puts(get<0>(d[index]).c_str());
        } else {
            puts("UNDETERMINED");
        }
    }
}

int main() 
{
    int T = 0;
    scanf("%d", &T);
    while (T--) {
        solve();
        if (T) {
            puts("");
        }
    }
}
