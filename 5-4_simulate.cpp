#include <iostream>
#include<vector>
#include<queue>
using namespace std;
struct process {
	int num;
	int arrive;
	int execute;
	int priority;
	bool operator<(const process p) const {
		if (priority == p.priority) {
			return num > p.num;
		}
		return priority < p.priority;
	}
};
int main() {
	process p;
	queue<process> q;
	while (cin >> p.num >> p.arrive >> p.execute >> p.priority) {
		q.push(p);
	}
	priority_queue<process> pq;
	int clock;
	process* executing = nullptr;
	while (1) {
		if (executing == nullptr) {
			clock = q.front().arrive;
			while (!q.empty() && q.front().arrive <= clock) {
				pq.push(q.front());
				q.pop();
			}
			executing = new process(pq.top());
			pq.pop();
		}
		else {
			if (q.empty()) {
				if (pq.empty()) {
					cout << executing->num << ' ' << executing->arrive + executing->execute << endl;
					break;
				}
				else {
					clock = executing->arrive + executing->execute;
					cout << executing->num << ' ' << executing->arrive + executing->execute << endl;
					delete executing;
					executing = new process(pq.top());
					executing->arrive = clock;
					pq.pop();
				}
			}
			else if (executing->arrive + executing->execute <= q.front().arrive) {
				clock = executing->arrive + executing->execute;
				cout << executing->num << ' ' << executing->arrive + executing->execute << endl;
				delete executing;
				if (pq.empty()) {
					clock = q.front().arrive;
					while (!q.empty() && q.front().arrive <= clock) {
						pq.push(q.front());
						q.pop();
					}
				}
				executing = new process(pq.top());
				executing->arrive = clock;
				pq.pop();
			}
			else {
				clock = q.front().arrive;
				while (!q.empty() && q.front().arrive <= clock) {
					pq.push(q.front());
					q.pop();
				}
				if (executing->priority < pq.top().priority) {
					executing->execute -= clock - executing->arrive;
					pq.push(*executing);
					executing = new process(pq.top());
					executing->arrive = clock;
					pq.pop();
				}
			}
		}
	}
}
