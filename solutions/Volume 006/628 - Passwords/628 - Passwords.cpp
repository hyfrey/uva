#include <vector>
#include <string>
#include <iostream>

using namespace std;

void dfs(string path, const vector<string> &words, const string &pattern, const int pos)
{
    if (pos == pattern.size()) {
        cout << path << endl;
        return;
    }
    
    if (pattern[pos] == '0') {
        for (int i = 0; i <= 9; ++i) {
            path.push_back('0' + i);
            dfs(path, words, pattern, pos+1);
            path.pop_back();
        }
    } else {
        for (const auto &word: words) {
            dfs(path + word, words, pattern, pos+1);
        }
    }
}

int main()
{
    int nd;
    while (scanf("%d", &nd) != EOF) {
        vector<string> words;
        for (int i = 0; i < nd; ++i) {
            string word;
            cin >> word;
            words.push_back(word);
        }
        
        puts("--");
        int np;
        scanf("%d", &np);
        for (int i = 0; i < np; ++i) {
            string pattern;
            cin >> pattern;
            string path;
            dfs(path, words, pattern, 0);
        }
    }
}