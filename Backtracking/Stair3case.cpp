#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using  namespace std;
#define int long long


void StairCase(int *a, int n, int i, int step, int* visited, int &ans) {

	if (i == n) {
		ans = min(ans, step);
		return;
	}


	//You are standing at the ith Staircase
	visited[i] = 1;

	if (i + 1 <= n and !visited[i + 1]) {
		StairCase(a, n, i + 1, step + 1, visited, ans);
	}


	if (i + a[i] <= n and i + a[i] >= 0 and !visited[i + a[i]]) {
		StairCase(a, n, i + a[i], step + 1, visited, ans);
	}

	visited[i] = 0;
	return;
}

int32_t main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int  visited[100005] = {0};
		int a[n + 1];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int ans = INT_MAX;
		StairCase(a, n, 0, 0, visited, ans);

		if (ans == INT_MAX) {
			cout << "-1" << endl;
		} else {
			cout << ans << endl;
		}
	}

}







