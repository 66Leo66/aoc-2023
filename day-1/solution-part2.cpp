#include <bits/stdc++.h>
using namespace std;

int sum = 0;
auto mapping = {
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
};
int check_prefix(string s) {
	for (int i = 0; auto it : mapping) {
		if (s.starts_with(it)) return i;
		i++;
	}
	for (int it : views::iota(0, 10)) {
		if (s[0] == '0' + it) return it;
	}
	return -1;
}
int check_suffix(string s) {
	for (int i = 0; auto it : mapping) {
		if (s.ends_with(it)) return i;
		i++;
	}
	for (int it : views::iota(0, 10)) {
		if (s.back() == '0' + it) return it;
	}
	return -1;
}
int main() {
	auto fin = ifstream("input.txt");
	string str;
	while (fin >> str) {
		while (true) {
			auto res = check_prefix(str);
			if (res == -1) {
				str = str.substr(1);
			} else {
				sum += res * 10;
				break;
			}
		}

		while (true) {
			auto res = check_suffix(str);
			if (res == -1) {
				str.pop_back();
			} else {
				sum += res;
				break;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
