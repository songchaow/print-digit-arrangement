#include<stdio.h>
#include <cmath>
#include <vector>
#define jingzi 10 


struct zhe {
	int a[jingzi];
};
zhe extra, sa, sb, ta, tb;
int d(int a, int b) {
	if (a > b)
		return(a - b);
	else
		return(b - a);
}

int DD(int* a, int* b) {
	int i, j = 0;
	for (i = 0; i < jingzi; i++)
	{
		if (d(a[i], b[i]) > j)
			j = d(a[i], b[i]);
	}
	return j;
}

void jiafa(zhe n) {
	int i;
	extra = n;
	extra.a[0]++;
	for (i = 0; i < jingzi; i++) {
		if (extra.a[i] >= jingzi) {
			extra.a[i + 1]++;
			extra.a[i] = extra.a[i] - jingzi;
		}
	}
}

int comp(zhe a, zhe b) {
	int i;
	for (i = jingzi - 1; i > -1; i--) {
		if (a.a[i] > b.a[i])return 1;
		if (a.a[i] < b.a[i])return -1;
	}
	return 0;
}

int same(zhe a) {
	int i, j;
	for (i = 0; i < jingzi - 1; i++)
		for (j = i + 1; j < jingzi; j++) {
			if (a.a[i] == a.a[j])
				return 0;
		}
	return 1;
}

int main()
{
	int D[2 * jingzi][jingzi];
	int i, j, r = 0, s, k = jingzi;
	r = jingzi - std::sqrt(jingzi + 3);
	// initial positions for r elements
	std::vector<int> ar;
	for (int i = 1; i <= r; i++)
		ar.push_back(i);

	return 0;
}

