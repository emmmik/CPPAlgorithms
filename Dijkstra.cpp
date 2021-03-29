#include <bits/stdc++.h>

using namespace std;

const int MaxN = 10000;
int d[MaxN];
int G[MaxN][MaxN];

void Dijkstra(int v, int n) {
    int way[n] = {0}, used[n] = {0};
    for (int i = 0; i < n; i++) {
        d[i] = 2147483646; // maximum int value
        used[i] = 0;
    }
    d[v] = 0;
    way[v] = -1;
    for (int steps = 0; steps < n; steps++) {
        // Step 1: finding the least and not already used element in an d array:
        int minR = 2147483647;
        int w = -1;
        for (int j = 0; j < n; j++) {
            if (used[j] == 0 && d[j] < minR) {
                w = j;
                minR = d[j];
            }
        }
        // Step 2: marking least element as already used:
        used[w] = 1;
        // Step 3: refreshing the results of the fastest ways to the graph vertex from the least vertex:
        for (int u = 0; u < n; u++) {
            if (G[w][u] > 0) {
                if (d[u] > d[w] + G[w][u]) {
                    d[u] = d[w] + G[w][u];
                    way[u] = w;
                }
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            G[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        x--;
        y--;
        G[x][y] = k;
        G[y][x] = k;
    }
    Dijkstra(0, n);
    for(int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
}

/*
 * testing input:
 * 7 11
 * 1 7 5
 * 1 6 3
 * 7 2 6
 * 6 2 7
 * 7 4 2
 * 6 5 2
 * 2 4 1
 * 2 5 4
 * 4 5 3
 * 4 3 6
 * 5 3 5
 * testing output (taken the first vertex, as example):
 * 0 8 10 7 5 3 5
 */
