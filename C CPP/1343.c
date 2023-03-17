#include <stdio.h>
#include <string.h>

int main() {
    char board[51] = {0, };

    scanf("%s", &board);

    int length = strlen(board), flag = 0, count = 0;

    for (int i = 0; i <= length; i++) {
        if (board[i] == 'X') count++;
        else {
            if (count % 2) {
                flag = 1;
                break;
            }
            else if (count % 4 == 2) {
                while (count > 2) {
                    board[i - count] = 'A';
                    count--;
                }
                board[i - 2] = 'B';
                board[i - 1] = 'B';
            }
            else {
                while (count > 0) {
                    board[i - count] = 'A';
                    count--;
                }
            }

            if (board[i] == 'X') count = 1;
            else count = 0;
        }        
    }

    if (count != 0 || flag == 1) printf("-1\n");
    else printf("%s\n", board);

    return 0;
    
}