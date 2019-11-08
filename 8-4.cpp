#include<iostream>
#include<cstring>
#include<algorithm>
#define SIZE 300
using namespace std;
int N, Q, top[SIZE + 1], children[SIZE + 1][3], value[SIZE + 1][3], dp[SIZE + 1][SIZE], sz[SIZE];
void dfs(int T, int parent) {
    int i, j, k;
    for (i = 0; i <= top[T]; i++) {
        if (children[T][i] != parent) {
            dfs(children[T][i], T);
            sz[T] += sz[children[T][i]] + 1;
            for (j = min(Q, sz[T]); j >= 1; j--) {
                for (k = j; k >= 1; k--) {
                    dp[T][j] = max(dp[T][j], dp[T][j - k] + value[T][i] + dp[children[T][i]][k - 1]);
                }
            }
        }
    }
}
int main() {
    memset(top, -1, sizeof(top));
    memset(dp, 0, sizeof(dp));
    memset(sz, 0, sizeof(sz));
    cin >> N >> Q;
    int i, a, b, v;
    for (i = 1; i <= N - 1; i++) {
        cin >> a >> b >> v;
        children[a][++top[a]] = b;
        value[a][top[a]] = v;
        children[b][++top[b]] = a;
        value[b][top[b]] = v;
    }
    dfs(1, 0);
    cout << dp[1][Q];
}
