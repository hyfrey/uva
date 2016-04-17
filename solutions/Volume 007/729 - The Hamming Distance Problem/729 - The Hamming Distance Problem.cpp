#include <string>
#include <iostream>

using namespace std;

void dfs(string &path, const int n, const int h, const int zeros, const int ones)
{
    if (path.size() == n) {
        cout << path << endl;
        return;
    }
    
    if (zeros > 0) {
        path.push_back('0');
        dfs(path, n, h, zeros-1, ones);
        path.pop_back();
    } 
    if (ones > 0) {
        path.push_back('1');
        dfs(path, n, h, zeros, ones-1);
        path.pop_back();
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        if (i != 0) {
            puts("");
        }
        
        int n,h;
        scanf("%d %d", &n, &h);
        
        string path;
        dfs(path, n, h, n-h, h);
    }
}