#include<stdio.h>
#pragma warning(disable:4996)






long long int mult(int a, int b, int c) {



	if (b == 1) return a%c;

	else if (b % 2 == 0) {


		return (mult(a, b / 2, c) % c) * (mult(a, b / 2, c)%c);
	}

	else if (b % 2 == 1) {

		return ((mult(a, b /2, c) % c)* (mult(a, b / 2, c) * a) % c);
	}

}



int main() {
	int a, b, c;
	int n;
	scanf("%d %d %d", &a, &b, &c);


	//while (c <= 2147483647/c) {
	//	c *= c;
	//}

	//printf("%d", c);


	n = mult(a, b, c);

	printf("%d", n);


}