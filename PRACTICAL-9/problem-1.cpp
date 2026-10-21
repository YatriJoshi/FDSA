#include <iostream>
#include <queue>
using namespace std;

int g[100][100], visited[100], n;

void dfs(int x) {
    cout << x << " ";
    visited[x] = 1;

    for (int i = 0; i < n; i++) {
        if (g[x][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}

void bfs(int s) {
    queue<int> q;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    q.push(s);
    visited[s] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        cout << x << " ";

        for (int i = 0; i < n; i++) {
            if (g[x][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int e, a, b, s;

    cout << "Enter number of buildings: ";
    cin >> n;

    cout << "Enter number of roads: ";
    cin >> e;

    for (int i = 0; i < e; i++) {
        cout << "Enter two buildings: ";
        cin >> a >> b;
        g[a][b] = 1;
        g[b][a] = 1;
    }

    cout << "Enter starting building: ";
    cin >> s;

    cout << "DFS: ";
    dfs(s);

    cout << "\nBFS: ";
    bfs(s);

    return 0;
}