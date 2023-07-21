#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using  namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>>v;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}


	for (pair<int, int>x : v) {
		cout << x.first << " " << x.second << endl;
	}

	sort(v.begin(), v.end());

	cout << endl << endl;

	for (pair<int, int>x : v) {
		cout << x.first << " " << x.second << endl;
	}


	// Container: 30, 19     30,17

}



