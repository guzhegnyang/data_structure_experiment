#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAXN 100
int n;
struct e {
    int n;
    int w;
};
vector<e> v[MAXN], u[MAXN], path_st;
void get_critical_path() {
    int i, j, indegree[MAXN], ve[MAXN], vl[MAXN], total = 0;
    vector<int> st;
    for (i = 0; i < n; i++) {
        indegree[i] = u[i].size();
        if (!indegree[i]) {
            st.push_back(i);
        }
        ve[i] = 0;
    }
    while (!st.empty()) {
        j = st.back();
        st.pop_back();
        for (i = 0; i < v[j].size(); i++) {
            ve[v[j][i].n] = max(ve[v[j][i].n], ve[j] + v[j][i].w);
            total = max(total, ve[v[j][i].n]);
            indegree[v[j][i].n]--;
            if (!indegree[v[j][i].n]) {
                st.push_back(v[j][i].n);
            }
        }
        st.pop_back();
    }
    for (i = 0; i < n; i++) {
        indegree[i] = v[i].size();
        if (!indegree[i]) {
            st.push_back(i);
            path_st.push_back({i, 0});
        }
        vl[i] = total;
    }
    while (!st.empty()) {
        j = st.back();
        st.pop_back();
        for (i = 0; i < u[j].size(); i++) {
            vl[u[j][i].n] = min(vl[u[j][i].n], vl[j] - u[j][i].w);
            if (ve[u[j][i].n] == vl[u[j][i].n]) {
                path_st.push_back(u[j][i]);
            }
            indegree[u[j][i].n]--;
            if (!indegree[u[j][i].n]) {
                st.push_back(u[j][i].n);
            }
        }
    }
}
int main() {
    cin >> n;
    int i, a, b, w;
    while (cin >> a >> b >> w) {
        v[a].push_back({b, w});
        u[b].push_back({a, w});
    }
    get_critical_path();
    for (i = 0; i < path_st.size(); i++) {
        cout << path_st[i].n << ' ';
    }
    cout << endl;
    for (i = 0; i < path_st.size(); i++) {
        cout << path_st[i].w << ' ';
    }
}
