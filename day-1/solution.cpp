#include <bits/stdc++.h>
using namespace std;

int sum = 0;
int main() {
	auto fin = ifstream("input.txt");
	string str;
	while (fin >> str) {
		for (auto it : str) {
			if ('0' <= it && it <= '9') {
				sum += (it - '0') * 10;
				break;
			}
		}
		for (auto it : str | views::reverse) {
			if ('0' <= it && it <= '9') {
				sum += (it - '0');
				break;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
