#include<iostream>
using  namespace std;
const int N = 10;
int n;
int grid[10][10];
int total = 0;
int ans = -1;

int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};


void Knight(int x, int y, int count) {

	ans = max(ans, count);

	//Currently i am standing at x,y.
	for (int i = 0; i < 8; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];


		if (next_x >= 0 and next_x<N and next_y >= 0 and next_y < N and grid[next_x][next_y] == 1) {

			grid[next_x][next_y] = 0;

			Knight(next_x, next_y, count + 1);

			grid[next_x][next_y] = 1;//Backtracking
		}
	}
}

void Input_Grid() {
	for (int i = 0; i < n; i++) {
		for (int  j = 0; j < n; j++) {
			cin >> grid[i][j];
			//We have to know what is the total number of  boxes where the  knight can move.
			if (grid[i][j] == 1) {
				total++;
			}
		}
	}
}

int main() {
	cin >> n;
	Input_Grid();

	grid[0][0] = 0;//Knight kisi bhi path me 0,0 par dubara nahi aayega.

	Knight(0, 0, 1);//3rd parameter is current path me kitne boxes aapne visit kiye.

	cout << total - ans << endl;

}












