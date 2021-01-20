#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 100000;
int _count[maxn], res[maxn];
vector<int> G[maxn];
priority_queue<int> que;

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        _count[u]++;
        G[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
        if (_count[i] == 0)
            que.push(i);
    int tmp = n;
    while (!que.empty()) {
        int u = que.top();
        que.pop();
        res[u] = tmp--;
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            _count[v]--;
            if (_count[v] == 0)
                que.push(v);
        }
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
