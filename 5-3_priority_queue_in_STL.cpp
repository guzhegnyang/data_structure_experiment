#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct flight {
	long long c;
	long long n;
	bool operator<(const flight& f) const;
};
bool flight::operator<(const flight& f) const{
	return c < f.c;
}
int main() {
	long long n, k, i, cost = 0;
	cin >> n >> k;
	vector<flight> v(n, { -1, -1 });
	vector<flight>::iterator iter;
	for (i = 0; i < n; i++) {
		cin >> v[i].c;
		v[i].n = i;
	}
	for (i = 0, iter = v.begin(); i < k; i++, iter++);
	priority_queue<flight> q(v.begin(), iter);
	for (; i < n; i++) {
		q.push(v[i]);
		cost += (i - q.top().n) * q.top().c;
		q.pop();
	}
	for (; i < n + k; i++) {
		cost += (i - q.top().n) * q.top().c;
		q.pop();
	}
	cout << cost;
}
