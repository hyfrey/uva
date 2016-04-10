#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int N;
        scanf("%d", &N);
        vector<int> v(N, 0);
        for (int i = 0; i < N; ++i) {
            int score;
            scanf("%d", &score);
            v[i] = score;
        }
        
        int max_score = v[0];
        int max_delta = max_score-v[1];
        for (int i = 1; i < v.size(); ++i) {
            max_score = max(max_score, v[i-1]);
            max_delta = max(max_delta, max_score-v[i]);
        }
        printf("%d\n", max_delta);
    }
}