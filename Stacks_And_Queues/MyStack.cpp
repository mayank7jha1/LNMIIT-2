#include<iostream>
#include<queue>
using  namespace std;


template<typename T>
//You are Implementing Stack with the help of 2 Queues
class MyStack {
public:
	queue<T>input, output;

	MyStack() {

	}

	void push(T x) {
		input.push(x);
	}

	T pop() {
		while (input.size() > 1) {
			T x = input.front();
			output.push(x);
			input.pop();
		}
		T Top_Element = input.front();
		input.pop();

		while (!output.empty()) {
			T x = output.front();
			input.push(x);
			output.pop();
		}

		return Top_Element;
	}

	T top() {
		while (input.size() > 1) {
			T x = input.front();
			output.push(x);
			input.pop();
		}

		T Top_Element = input.front();
		output.push(Top_Element);
		input.pop();

		while (!output.empty()) {
			T x = output.front();
			input.push(x);
			output.pop();
		}
		return Top_Element;
	}

	bool empty() {
		if (input.empty() == 1) {
			return true;
		} else {
			return false;
		}
	}
};



int main() {

	MyStack<int>st;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		st.push(x);
	}

	while (!st.empty()) {
		//cout << st.top() << " ";
		cout << st.pop() << " ";
	}
}












