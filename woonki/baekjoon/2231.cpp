#include<stdio.h>

int main() {
	int n;
	bool check = false;
	scanf("%d", &n);

	for (int m = 1; m < n; m++) {

		int tmp = m;
		int answer = m;

		while (tmp != 0) {
			answer += tmp % 10;
			tmp /= 10;
			
		}

		if (answer == n) {
			printf("%d", m);
			check = true;
			break;
		}

		

	}

	if (!check) printf("0");

}