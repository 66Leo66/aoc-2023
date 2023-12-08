#include <ranges>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll dimension = 1e4 + 10;
using blueprint_t = array<string, dimension>;

blueprint_t blueprint;
ll sum = 0;


ll diffuseNumber(int x, int y) {
	ll n = 0;
	bool flag = false;
	auto char_is_digit = [](const char& c) {
		return isdigit(c);
	};
	// left
	for (char& ch : blueprint[x] | views::take(y) | views::reverse | views::take_while(char_is_digit) | views::reverse) {
		n = n * 10 + (ch - '0');
		// cout << format("read {}, have {}", ch, n) << endl;
		ch = '.';
		flag = true;
	}
	// right
	for (char& ch : blueprint[x] | views::drop(y) | views::take_while(char_is_digit)) {
		n = n * 10 + (ch - '0');
		// cout << format("read {}, have {}", ch, n) << endl;
		ch = '.';
		flag = true;
	}

	// cout << format("(L{}, C{}) read {}", x + 1, y + 1, n) << endl;
	// cout << n << endl;
	return flag ? n : -1;
}

void scanPos(int x, int y) {
	auto offset = {-1, 0, 1};
	ll cnt = 0, val = 1;
	for (auto i : offset) {
		for (auto j : offset) {
			if (isdigit(blueprint[x + i][y + j])) {
				// diffuse
				auto res = diffuseNumber(x + i, y + j);;
				if (res != -1) {
					cnt ++;
					val *= res;
				}
			}
		}
	}
	if (cnt == 2) sum += val;

}

int main() {
	auto fin = ifstream("input.txt");
	int ii = 0;
	while (fin >> blueprint[ii]) ii++;

	const auto bak = blueprint;
	for (auto const [i, line] : blueprint | views::enumerate) {
		for (auto const [j, ch] : line | views::enumerate) {
			if (ch == '*') {
				// Scan around
				scanPos(i, j);
				blueprint = bak;
			}
		}
	}

	cout << sum << endl;
	return 0;
}
