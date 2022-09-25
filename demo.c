#include <stdio.h>
#include <cstring>
int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

	int cnt = 1;
	int ans = arr[0];
	for(int i = 1; i < n; i++) {
		if(arr[i] != ans) {	
			cnt--;
		}
		else {
			cnt++;
		}
		if(cnt == 0) {
			ans = arr[i];
			cnt = 1;
		}
	}
	cnt = 0;
	for(int i = 0; i < n; i++) {
		if(arr[i] == ans) cnt++;
	}
	if(cnt > n / 2) {
		printf("%d", ans);
	}
	else {
		printf("-1");
	}
	
}