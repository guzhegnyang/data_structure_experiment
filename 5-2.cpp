#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m;
int main() {
    scanf("%d %d", &n, &m);
    int t = 1;
    queue<int> q1, q2;
    vector<char> s, a;
    while (n--) {
        q1.push(2 * t + 1);
        q2.push(4 * t + 5);
        for (; t; t /= 10) {
            s.push_back(t % 10 + '0');
        }
        for (; !s.empty(); s.pop_back()) {
            putchar(s.back());
            a.push_back(s.back());
        }
        if (q1.front() < q2.front()) {
            t = q1.front();
            q1.pop();
        }
        else {
            t = q2.front();
            q2.pop();
        }
    }
    putchar('\n');
    int l, r;
    for (l = 0, r = m; r < a.size(); l++, r++) {
        for (t = l; t <= r; t++) {
            if (a[t] > a[l]) {
                l = t;
            }
        }
        putchar(a[l]);
    }
}
