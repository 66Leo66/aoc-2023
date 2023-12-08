#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll score = 0;
set<int> winning;
enum State { read, check };
State st = read;
int val = 1;

int main() {
	auto fin = ifstream("input.txt");
	string str;
	while (fin >> str) { // Card
		if (str == "Card") {
			if (val != 1) score += val / 2;
			
			winning.clear();
			fin >> str;
			st = read;
			val = 1;
		} else if (str == "|") {
			st = check;
		} else {
			switch (st) {
				case read:
					winning.insert(stoi(str));
					break;
				case check:
					val *= winning.contains(stoi(str)) ? 2 : 1;
				break;
			}
		}
	}
	cout << score << endl;
	return 0;
}
