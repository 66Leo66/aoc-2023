#include <bits/stdc++.h>
using namespace std;

long long sum = 0;
int gameId;

int cnt;
string color;
char tmp;

array<long long, 3> total = {0, 0, 0};
array<long long, 3> least = {0, 0, 0};
int main() {
	auto fin = ifstream("input.txt");
	string str;
	while (fin >> str) {
		least.fill(0);
		fin >> gameId;
		fin >> tmp; // :
//		cout << "Started game "<< gameId << endl;
		
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
				for (auto it : {0, 1, 2}) {
					least[it] = max(least[it], total[it]);
				}
				total.fill(0);
			} else if (!color.ends_with(',')) {
				// end of game
//				cout << "Game Ended" << endl;
				for (auto it : {0, 1, 2}) {
					least[it] = max(least[it], total[it]);
				}
				sum += least[0] * least[1] * least[2];
				total.fill(0);
				break;
			}
		}
	}
	cout << sum;
	return 0;
}
