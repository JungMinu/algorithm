#include <cstdlib>
#include <cstdio>

int dx[] = { 0,  1,  1,  1,  0, -1, -1, -1};
int dy[] = {-1, -1,  0,  1,  1,  1,  0, -1};

int main() {
    int T;
	scanf("%d", &T);
	while (T--) {
		char map[6][6];
		for (int i = 0; i < 5; i++) scanf("%s", map[i]);
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			char str[11];
			int check[11][5][5] = {0};
			scanf("%s", str);
			bool ok = false;
			for (int j = 0; str[j]; j++) {
				for (int y = 0; y < 5; y++) {
					for (int x = 0; x < 5; x++) {
						if (check[j][y][x] == j && map[y][x] == str[j]) {
							for (int k = 0; k < 8; k++) {
								int ny = y + dy[k];
								int nx = x + dx[k];
								if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
								check[j+1][ny][nx] = j+1;
								if (str[j+1] == 0) {
									ok = true;
									goto EXIT_LOOP;
								}
							}
						}
					}
				}
			}
EXIT_LOOP:;

		  printf("%s %s\n", str, ok ? "YES" : "NO");
		}
	}
	return 0;
}
