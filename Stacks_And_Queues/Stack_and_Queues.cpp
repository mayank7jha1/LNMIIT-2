#include<iostream>
#include<stack>
#include<queue>
using  namespace std;


//Stack and Queue : Arrays/Vector

int main() {
	int  n;
	cin >> n;

	stack<int>st, st1;
	queue<int>q;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		st.push(x);
		q.push(x);
	}

	cout << q.size() << endl;
	cout << q.back() << endl;

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
	st1 = st;

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
}



//x=10
// 15
// 14
// 13
// 12
// 10

// 10 12 13 14 15














