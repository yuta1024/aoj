#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int n, ans;
int used[10], assign[26];
char exp[12][9], exist[10+1];

// Verbal Arithmetic(1161)
void solve(int idx)
{
	if (idx == strlen(exist)) {
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			int num = 0;
			int len = strlen(exp[i]);
			if (len > 1 && assign[exp[i][0]-'A'] == 0)
				return;
			for (int j = 0; j < len; ++j) {
				num *= 10;
				num += assign[exp[i][j]-'A'];
			}
			if (i < n-1)
				sum += num;
			else if (sum == num)
				++ans;
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; ++i) {
		if (!used[i]) {
			used[i] = 1;
			assign[exist[idx]-'A'] = i;
			solve(idx+1);
			used[i] = 0;
			assign[exist[idx]-'A'] = -1;
		}
	}
}

int main()
{
	freopen("C1", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		if (n == 0)
			break;

		for (int i = 0; i < n; ++i)
			scanf("%s", &exp[i]);

		set<char> tmp;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < strlen(exp[i]); ++j)
				tmp.insert(exp[i][j]);
		}

		int i = 0;
		for (set<char>::iterator it = tmp.begin(); it != tmp.end(); ++it, ++i)
			exist[i] = (*it);
		exist[i] = '\0';

		ans = 0;
		solve(0);
		cout << ans << endl;
		
	}

	return 0;
}
