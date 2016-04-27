#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <iostream>

using namespace std;

const int RD[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int CD[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int LEN = 3;

void dfs(map<int, set<string>> &result, string &path, vector<string> &maze, int r, int c, const int N)
{
    if (r < 0 || c < 0 || r >= N || c >= N) {
        return;
    }
    if (!path.empty() && path.back() >= maze[r][c]) {
        return;
    }
    path.push_back(maze[r][c]);
    if (path.size() >= LEN) {
        auto &words = result[path.size()];
        words.insert(path);
    }
    for (int i = 0; i < 8; ++i) {
        dfs(result, path, maze, r+RD[i], c+CD[i], N);
    }
    path.pop_back();
}

void solve()
{
    int N;
    scanf("%d", &N);
    vector<string> maze;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        maze.push_back(s);
    }
    
    map<int,set<string>> result;
    string path;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            dfs(result, path, maze, r, c, N);
        }
    }
    for (auto &pp: result) {
        for (auto &word: pp.second) {
            cout << word << endl;
        }
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
        solve();
    }
}