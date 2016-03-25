#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        vector<int> nums;
        nums.reserve(N);
        for (int i = 0; i < N; ++i) {
            int num;
            scanf("%d", &num);
            nums.push_back(num);
        }
        
        int sum = 0;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] <= nums[i]) {
                    sum++;
                }
            }
        }
        
        printf("%d\n", sum);
    }
}