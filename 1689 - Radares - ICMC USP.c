#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max (int a, int b){
  if (a>b){
    return a;
  } else {
    return b;
  }
}

int main() {
  int dp[1000001], pos[1000001], v[1000001];
	int T, i;
	scanf("%d", &T);

	while(T--){
		int n, k, j=0;
		scanf("%d %d", &n, &k);

		for(i = 1; i <= n; i++){
		    scanf("%d", &pos[i]);
		}

		for(i = 1; i <= n; i++){
		    scanf("%d", &v[i]);
		}

		for(i = 1; i <= n; i++) {
			while(pos[i]-pos[j+1] >= k) j++;
			dp[i] = max(dp[i-1], v[i]+dp[j]);
		  }

		printf("%d\n", dp[n]);
	}
	return 0;
}
