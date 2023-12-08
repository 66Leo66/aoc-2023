#include <bits/stdc++.h>
using namespace std;

int sum = 0;
int gameId;

int cnt;
string color;
char tmp;

array<int, 3> total = {0, 0, 0};
int main() {
	auto fin = ifstream("input.txt");
	string str;
	while (fin >> str) {

		fin >> gameId;
		fin >> tmp; // :
		bool isPossible = true;

		while (true) {
			// a group of fetch
			fin >> cnt >> color;
			if (color.starts_with("red")) {
				total[0] += cnt;
			} else if (color.starts_with("green")) {
				total[1] += cnt;
			} else {
				// blue
				total[2] += cnt;
			}

			if (color.ends_with(';')) {
				// end of group
				if (total[0] > 12 || total[1] > 13 || total[2] > 14) {
					isPossible = false;
				}
				total.fill(0);
			} else if (!color.ends_with(',')) {
				// end of game
				if (total[0] > 12 || total[1] > 13 || total[2] > 14) {
					isPossible = false;
				}
				if (isPossible) {
					sum += gameId;
				}
				total.fill(0);
				break;
			}
		}
	}
	cout << sum;
	return 0;
}
