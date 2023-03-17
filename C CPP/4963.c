#include <stdio.h>

int w, h, island;
int map[52][52], visited[52][52];
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

void reset() {
    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 52; j++) {
            map[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

void dfs(int x, int y) {
    visited[x][y] = 1;

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
            if (map[nx][ny] == 1) {
                if (!visited[nx][ny]) {
                    dfs(nx, ny);
                }
            }
        }
        else continue;
    }

}   

int main() {

    scanf("%d %d", &w, &h);

    while (w > 0 && h > 0) {
        island = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] == 1) {
                    if (!visited[i][j]) {
                        island++;
                        dfs(i, j);
                    }
                }
            }
        }

        printf("%d\n", island);
        reset();
        scanf("%d %d", &w, &h);
    }    
    return 0;
}