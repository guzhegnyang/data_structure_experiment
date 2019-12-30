#include<iostream>
#include<vector>
using namespace std;
#define MAXN 100
int n, E[MAXN][MAXN];
struct t {
    int distance;
    vector<int> path;
} dp[MAXN];
void dijkstra() {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (k = 1, j = 2; j < n; j++) {
            if (dp[k].distance > dp[j].distance) {
                k = j;
            }
        }
        for (j = 1; j < n; j++) {
            if (dp[j].distance > dp[k].distance + E[k][j]) {
                dp[j].distance = dp[k].distance + E[k][j];
                dp[j].path = dp[k].path;
                dp[j].path.push_back(j);
            }
        }
    }
}
int main() {
    cin >> n;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> E[i][j];
        }
        dp[i].distance = E[0][i];
        dp[i].path = {0, i};
    }
    dijkstra();
    for (i = 1; i < n; i++) {
        cout << dp[i].distance << ' ';
    }
}
