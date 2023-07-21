#include<iostream>
#include<vector>
using  namespace std;

int main() {
	int n;
	cin >> n;

	vector<int>v;

	for (int i = 0; i < n; i++) {
		// cin >> v[i];
		int x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
}


// 8
// 30 1
// 30 -19
// 30 7
// 19 18
// 19  5
// 19 1
// 20  22
// 20 5