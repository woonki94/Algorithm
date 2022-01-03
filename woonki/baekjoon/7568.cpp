#include<stdio.h>
#include<vector>

using namespace std;
int main() {
	int stu[51][2] = { 0, };
	int n;
	scanf("%d", &n);
	vector<int> cnt(n,1);

	for (int i = 0; i < n; i++) {
		scanf("%d\t%d", &stu[i][0], &stu[i][1]);
	}

	for (int i = 0; i < n; i++) {
		int weight = stu[i][0];
		int height = stu[i][1];
		for (int j = 0; j < n; j++) {
			if (weight < stu[j][0] && height < stu[j][1]) {
				cnt[i]++;
			}

		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", cnt[i]);
	}
	
}