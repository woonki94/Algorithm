#include<stdio.h>
#include<vector>


using namespace std;

int main() {
	int n;
	int m;	
	int max=-1;
	scanf("%d%d", &n, &m);
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	for (int i = 0; i < n-2; i++) {
		for (int j = i+1; j < n-1; j++) {
			for (int k = j+1; k < n; k++) {
				int new_max = (v[i] + v[j] + v[k]);
				if (new_max <= m && max < new_max) max = (v[i] + v[j] + v[k]);
			}
		}
	}

	printf("%d", max);

}