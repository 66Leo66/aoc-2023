#include <bits/stdc++.h>
using namespace std;
using ll = long long;

namespace solution1 {
	set<int> winning;
	enum State { read, check };
	State st = read;
	int val = 0;
	
	int readcard(string c) {
		auto fin = istringstream(c);
		string str;
		while (fin >> str) { // Card
			if (str == "Card") {				
				winning.clear();
				fin >> str;
				st = read;
				val = 0;
			} else if (str == "|") {
				st = check;
			} else {
				switch (st) {
				case read:
					winning.insert(stoi(str));
					break;
				case check:
					val += winning.contains(stoi(str)) ? 1 : 0;
					break;
				}
			}
		}
		
		return val;
	}
}

vector<string> cards;
vector<int> card_cnt;
int consumed = 0;

int main() {
	auto fin = ifstream("input.txt");
	
	for (string line; getline(fin, line);) {
		cards.push_back(line);
		card_cnt.push_back(1);
	}
	
	while (true) {
		bool processed = false;
		for (auto [i, cnt] : card_cnt | views::enumerate) {
			if (cnt > 0) {
				processed = true;
				int score = solution1::readcard(cards[i]);
				for(auto idx : views::iota(i + 1) | views::take(score)) {
					card_cnt[idx] += cnt;
				}
				consumed += cnt;
				cnt = 0;
			}
		}
		if (!processed) break;
	}
	cout << consumed << endl;
	return 0;
}
