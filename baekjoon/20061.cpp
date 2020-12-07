#include <iostream>
using namespace std;

int blockCount, type, x, y, score;
int green[6][4], botGreen = 5;
int blue[4][6], rightBlue = 5;

void insertBlock() {
    if (type == 1) {
        int emptyRow = (botGreen + 1) % 6;
        for (int i = 0; i < 5; i++) {
            int nextRow = (emptyRow + 1) % 6;
            if (green[nextRow][y] == 1) break;
            emptyRow = nextRow;
        }
        green[emptyRow][y] = 1;

        int emptyCol = (rightBlue + 1) % 6;
        for (int i = 0; i < 5; i++) {
            int nextCol = (emptyCol + 1) % 6;
            if (blue[x][nextCol] == 1) break;
            emptyCol = nextCol;
        }
        blue[x][emptyCol] = 1;
    }
    else if (type == 2)
    {
        int emptyRow = (botGreen + 1) % 6;
        for (int i = 0; i < 5; i++) {
            int nextRow = (emptyRow + 1) % 6;
            if (green[nextRow][y] == 1 || green[nextRow][y + 1] == 1) break;
            emptyRow = nextRow;
        }
        green[emptyRow][y] = 1;
        green[emptyRow][y + 1] = 1;

        int emptyCol = (rightBlue + 1) % 6;
        for (int i = 0; i < 5; i++) {
            int nextCol = (emptyCol + 1) % 6;
            if (blue[x][nextCol] == 1) break;
            emptyCol = nextCol;
        }
        blue[x][emptyCol] = 1;
        blue[x][(emptyCol + 5) % 6] = 1;
    }
    else if (type == 3)
    {
        int emptyRow = (botGreen + 1) % 6;
        for (int i = 0; i < 5; i++) {
            int nextRow = (emptyRow + 1) % 6;
            if (green[nextRow][y] == 1) break;
            emptyRow = nextRow;
        }
        green[emptyRow][y] = 1;
        green[(emptyRow + 5) % 6][y] = 1;

        int emptyCol = (rightBlue + 1) % 6;
        for (int i = 0; i < 5; i++) {
            int nextCol = (emptyCol + 1) % 6;
            if (blue[x][nextCol] == 1 || blue[x + 1][nextCol] == 1) break;
            emptyCol = nextCol;
        }
        blue[x][emptyCol] = 1;
        blue[x + 1][emptyCol] = 1;
    }
}

void check() {
    // Green
    for (int i = 0; i < 4;) {
        int searchRow = (botGreen + 6 - i) % 6;
        if (green[searchRow][0] == 1
                && green[searchRow][1] == 1
                && green[searchRow][2] == 1
                && green[searchRow][3] == 1) {
            for (int startRow = searchRow; startRow != (botGreen + 1) % 6; ) {
                int nextRow = (startRow + 5) % 6;
                green[startRow][0] = green[nextRow][0];
                green[startRow][1] = green[nextRow][1];
                green[startRow][2] = green[nextRow][2];
                green[startRow][3] = green[nextRow][3];
                startRow = nextRow;
            }
            green[(botGreen + 1) % 6][0] = 0; 
            green[(botGreen + 1) % 6][1] = 0; 
            green[(botGreen + 1) % 6][2] = 0; 
            green[(botGreen + 1) % 6][3] = 0; 

            score++;
        }
        else
            ++i;
    }

    while(true) {
        int exploreRow = (botGreen + 6 - 4) % 6;

        if (green[exploreRow][0] == 1
                || green[exploreRow][1] == 1
                || green[exploreRow][2] == 1
                || green[exploreRow][3] == 1) {
            green[botGreen][0] = 0; 
            green[botGreen][1] = 0; 
            green[botGreen][2] = 0; 
            green[botGreen][3] = 0; 

            botGreen = (botGreen + 5) % 6;
        }
        else
            break;
    }

    // Blue
    for (int i = 0; i < 4;){
        int searchCol = (rightBlue + 6 - i) % 6;
        if (blue[0][searchCol] == 1
                && blue[1][searchCol] == 1
                && blue[2][searchCol] == 1
                && blue[3][searchCol] == 1) {
            for (int startCol = searchCol; startCol != (rightBlue + 1) % 6; ) {
                int nextCol = (startCol + 5) % 6;
                blue[0][startCol] = blue[0][nextCol];
                blue[1][startCol] = blue[1][nextCol];
                blue[2][startCol] = blue[2][nextCol];
                blue[3][startCol] = blue[3][nextCol];
                startCol = nextCol;
            }
            blue[0][(rightBlue + 1) % 6] = 0; 
            blue[1][(rightBlue + 1) % 6] = 0; 
            blue[2][(rightBlue + 1) % 6] = 0; 
            blue[3][(rightBlue + 1) % 6] = 0; 

            score++;
        }
        else
            ++i;
    }

    while(true) {
        int exploreCol = (rightBlue + 6 - 4) % 6;

        if (blue[0][exploreCol] == 1
                || blue[1][exploreCol] == 1
                || blue[2][exploreCol] == 1
                || blue[3][exploreCol] == 1) {
            blue[0][rightBlue] = 0; 
            blue[1][rightBlue] = 0; 
            blue[2][rightBlue] = 0; 
            blue[3][rightBlue] = 0; 

            rightBlue = (rightBlue + 5) % 6;
        }
        else
            break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> blockCount;
    for (int blockIndex = 0; blockIndex < blockCount; ++blockIndex) {
        cin >> type >> x >> y;

        insertBlock();
        check();
    }

    int ans = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            ans += green[(botGreen + 6 - i) % 6][j];
            ans += blue[i][(rightBlue + 6 - j) % 6];
        }
    }

    cout << score << '\n' << ans << '\n';

    return 0;
}
