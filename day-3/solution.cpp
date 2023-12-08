#include <ranges>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll dimension = 1e5 + 10;
array<string, dimension> blueprint;
ll sum = 0;


ll diffuseNumber(int x, int y) {
	ll n = 0;
	auto char_is_digit = [](const char& c) {
		return isdigit(c);
	};
	// left
	for (char& ch : blueprint[x] | views::take(y) | views::reverse | views::take_while(char_is_digit) | views::reverse) {
		n = n * 10 + (ch - '0');
		// cout << format("read {}, have {}", ch, n) << endl;
		ch = '.';
	}
	// right
	for (char& ch : blueprint[x] | views::drop(y) | views::take_while(char_is_digit)) {
		n = n * 10 + (ch - '0');
		// cout << format("read {}, have {}", ch, n) << endl;
		ch = '.';
	}

	// cout << format("(L{}, C{}) read {}", x + 1, y + 1, n) << endl;
	// cout << n << endl;
	return n;
}

void scanPos(int x, int y) {
	auto offset = {-1, 0, 1};
	for (auto i : offset) {
		for (auto j : offset) {
			if (isdigit(blueprint[x + i][y + j])) {
				// diffuse
				sum += diffuseNumber(x + i, y + j);
			}
		}
	}

}

int main() {
	auto fin = ifstream("input.txt");
	int ii = 0;
	while (fin >> blueprint[ii]) ii++;

	for (auto const [i, line] : blueprint | views::enumerate) {
		for (auto const [j, ch] : line | views::enumerate) {
			if (ch != '.' && !isdigit(ch)) {
				// Scan around
				scanPos(i, j);
			}
		}
	}

	cout << sum << endl;

	auto fout = ofstream("processed.txt");
	for (auto line : blueprint) {
		if (line.empty()) break;
		fout << line << endl;
	}
	return 0;
}
