#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int F,R;
    while (scanf("%d %d", &F, &R) != EOF && F != 0) {
        vector<double> ratios;
        ratios.reserve(F*R);
        vector<int> fs;
        fs.reserve(F);
        vector<int> rs;
        rs.reserve(R);
        
        for (int i = 0; i < F; ++i) {
            int f;
            scanf("%d", &f);
            fs.push_back(f);
        }
        for (int i = 0; i < R; ++i) {
            int r;
            scanf("%d", &r);
            rs.push_back(r);
        }
        
        for (int i = 0; i < F; ++i) {
            for (int j = 0; j < R; ++j) {
                ratios.push_back(rs[j]*1.0/fs[i]);
            }
        }
        sort(ratios.begin(), ratios.end());
        
        double _max = 0.0;
        for (int i = 1; i < ratios.size(); ++i) {
            _max = max(ratios[i]/ratios[i-1], _max);
        }
        printf("%.2f\n", _max);
    }
}