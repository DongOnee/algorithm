#include <stdio.h>

int n, ans, u[33], l[33], r[33];
void dfs(int h, int c) {
    printf("h:%d | c:%d\n", h, c);
	if (c == n) {
        ans++;
        printf("=P=L=U=S=\n");
        return;
	}
	for (int i = 0; i < n; i++) {
        printf("i:%d\n", i);
		if (u[i] || l[i + h] || r[i - h + 14]) continue;
		u[i] = l[i + h] = r[i - h + 14] = 1;
		dfs(h + 1, c + 1);
		u[i] = l[i + h] = r[i - h + 14] = 0;
    }
    printf("=========\n");
}

int main() {
	scanf("%d", &n);
	dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}