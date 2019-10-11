#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main() {
    int n, m, i;
    cin >> n >> m;
    int * a = new int[n],\
        * q1 = new int[2 * n + 1], f1 = 0, r1 = 0,\
        * q2 = new int[2 * n + 1], f2 = 0, r2 = 0;
    a[0] = 1, q1[0] = 3, q2[0] = 9;
    for (i = 1; i < n; i++) {
        if (q1[f1] < q2[f2]) {
            a[i] = q1[f1];
            f1++;
        }
        else {
            a[i] = q2[f2];
            f2++;
        }
        r1++;
        q1[r1] = 2 * a[i] + 1;
        r2++;
        q2[r2] = 4 * a[i] + 5;
    }
    queue<int> bucket[10];
    int index = -1, size = 0;
    for (i = 0; i < n; i++) {
        cout << a[i];
        vector<int> stack;
        while (a[i] > 0) {
            stack.push_back(a[i] % 10);
            a[i] /= 10;
        }
        while (!stack.empty()) {
            index++;
            bucket[stack.back()].push(index);
            stack.pop_back();
            size++;
        }
    }
    cout << endl;
    int num, current = -1;
    for (i = 0; i < size - m; i++) {
        for (num = 9; num >= 0; num--) {
            int j = bucket[num].front();
            while (bucket[num].size() != 0 && j <= current) {
                bucket[num].pop();
                j = bucket[num].front();
            }
            if (bucket[num].size() != 0 && j <= m + i) {
                current = j;
                cout << num;
                bucket[num].pop();
                break;
            }
        }
    }
}
