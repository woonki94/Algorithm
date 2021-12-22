#include<stdio.h>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

int main() {

	int n;
	scanf("%d", &n);
	vector<int> ans(n, 0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ans[i]);
	}

	vector<vector<int>> count(100, vector<int>(100, 0));

	count[0][0] = 1;
	count[0][1] = 0;

	count[1][0] = 0;
	count[1][1] = 1;



	for (int i = 0; i < n; i++) {
		if (ans[i] == 0) {
			printf("%d %d\n", count[0][0], count[1][0]);
		}
		else if (ans[i] == 1) {
			printf("%d %d\n", count[0][1], count[1][1]);
		}
		else {
			int j;
			for (j = 2; j <= ans[i]; j++) {
				count[0][j] = count[0][j - 1] + count[0][j - 2];
				count[1][j] = count[1][j - 1] + count[1][j - 2];

			}
			printf("%d %d\n", count[0][j - 1], count[1][j - 1]);
		}
	}




	/*

	for (int i = 0; i < n; i++) {
		scanf("%d", &ans[i]);
	}

	for (int i = 0; i < n; i++) {

	}

	printf("\n");


	vector<int> a;
	a.push_back(0);
	a.push_back(1);
	a.push_back(1);
	for (int i = 3; i < 10; i++) {
		a.push_back(a[i - 1] + a[i - 2]);

	}

	for (int i = 0; i < 10; i++) {
		printf("%d", a[i]);
	}

	*/




	printf("\n\n\n%d", w(10, 4, 6));







}