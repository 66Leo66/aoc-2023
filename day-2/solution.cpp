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
//		cout << "Started game "<< gameId << endl;
		bool isPossible = true;
		
		while (true) {
			// a group of fetch
			fin >> cnt >> color;
//			cout << cnt <<" "<< color << endl;
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
//				cout << "Group ended" << endl;
				if (total[0] > 12 || total[1] > 13 || total[2] > 14) {
					isPossible = false;
				}
				total.fill(0);
			} else if (!color.ends_with(',')) {
				// end of game
//				cout << "Game Ended" << endl;
				if (total[0] > 12 || total[1] > 13 || total[2] > 14) {
					isPossible = false;
				}
				if (isPossible) {
//					cout << "Game is possible" << endl;
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
