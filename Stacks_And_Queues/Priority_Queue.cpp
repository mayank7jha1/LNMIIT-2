#include<iostream>
#include <queue>
using  namespace std;

int main() {
	priority_queue<int>pq;//Max Priority Queue
	priority_queue<int, vector<int>, greater<int>>pq1;//Min Priority Queue

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pq.push(x);
		pq1.push(x);
	}
	//nlogn
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

	while (!pq1.empty()) {
		cout << pq1.top() << " ";
		pq1.pop();
	}
}