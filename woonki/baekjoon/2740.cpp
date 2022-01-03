#include<stdio.h>





int main() {



	//for (int i = 0; i < ans.size(); i++) {
	//	printf("%d\n", ans[i]);
	//}


	//printf("%d %d", *(a[0]+1), *(b[0]+1));


	int n, m, k;
	int a[101][101] = { 0, };
	int b[101][101] = { 0, };
	
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	scanf("%d%d", &m, &k);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			scanf("%d", &b[i][j]);
		}
	}

	int tmp = 0;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < k; j++) {

			for (int l = 0; l < m; l++) {
				tmp += (*(a[i] + l)) * (*(b[l] + j));
			}
			//ans.push_back(tmp);
			printf("%d ", tmp);
			tmp = 0;
		}
		printf("\n");
	}

}