#include <iostream>
#include <vector>

using namespace std;

typedef struct _cmd{
    int _t;
    int _x;
    int _y;
    _cmd(int t, int x, int y) :  _t(t), _x(x), _y(y) {};
}cmd;

typedef pair<int,int> pii;

// const pii dirs[2] = {{1,0}, {0,1}};

int n, score, boardCnt; 
vector<cmd> cmds;

bool blueBoard[4][4];
int blueStartCol = 3;

bool greenBoard[4][4];
int greenStartRow = 3;

int idxFirstEmpty(pii xy, bool isBlue) {
    int ret = 0;
    for (; ret < 4; ret++) {
        if (isBlue && blueBoard[xy.first][(blueStartCol + 1 + ret) % 4]) break;
        if (!isBlue && greenBoard[(greenStartRow + 1 + ret) % 4][xy.second]) break;
    }
    return ret;
}

void greenCheck() {
    bool ret = true;
    while (ret) {
        ret = false;
        // check board
        for (int i = 0; i < 4; i++) {
            int lineNumber = (greenStartRow + 4 - i) % 4;
            ret = greenBoard[lineNumber][0] 
                && greenBoard[lineNumber][1] 
                && greenBoard[lineNumber][2] 
                && greenBoard[lineNumber][3];

            if (ret) {
                for (int col = 0; col < 4; col++) {
                    greenBoard[lineNumber][col] = false;

                    int falseRow = greenStartRow;
                    while (true == greenBoard[falseRow][col]) {
                        falseRow = (falseRow - 1 + 4) % 4;
                    }
                    
                    int searchRow = (falseRow - 1 + 4) % 4;
                    while (searchRow != greenStartRow) {
                        if (greenBoard[searchRow][col]) {
                            greenBoard[falseRow][col] = true;
                            greenBoard[searchRow][col] = false;

                            do  {
                                falseRow = (falseRow - 1 + 4) % 4;
                            } while (true == greenBoard[falseRow][col]);
                        }

                        searchRow = (searchRow - 1 + 4) % 4;
                    } 
                }

                score++;

                break;
            }

        }
    }
}

void blueCheck() {
    bool ret = true;
    while (ret) {
        ret = false;
        // check board
        for (int i = 0; i < 4; i++) {
            int lineNumber = (blueStartCol + 4 - i) % 4;
            ret =  blueBoard[0][lineNumber] 
                && blueBoard[1][lineNumber] 
                && blueBoard[2][lineNumber] 
                && blueBoard[3][lineNumber];
            if (ret) {
                for (int row = 0; row < 4; row++) {
                    blueBoard[row][lineNumber] = false;

                    int falseCol = blueStartCol;
                    while (true == blueBoard[row][falseCol]) {
                        falseCol = (falseCol - 1 + 4) % 4;
                    }
                    
                    int searchCol = (falseCol - 1 + 4) % 4;
                    while (searchCol != blueStartCol) {
                        if (blueBoard[row][searchCol]) {
                            blueBoard[row][falseCol] = true;
                            blueBoard[row][searchCol] = false;

                            do  {
                                falseCol = (falseCol - 1 + 4) % 4;
                            } while (true == blueBoard[row][falseCol]);
                        }

                        searchCol = (searchCol - 1 + 4) % 4;
                    }
                }

                score++;

                break;
            }
        }
    }
}

void runBlue(const cmd& command) {
    int t = command._t;
    int x = command._x;
    int y = command._y;
    int firstIndex;
    
    switch (t) {
        case 1:
            firstIndex = idxFirstEmpty({x, y}, true);
            if (firstIndex == 0) { // 맨 시작 col 초기화됨
                for (int i = 0; i < 4; i++) {
                    blueBoard[i][blueStartCol] = false;
                }
                blueBoard[x][blueStartCol] = true;
                blueStartCol = (blueStartCol - 1 + 4) % 4;
            }
            else {
                blueBoard[x][(blueStartCol + firstIndex) % 4] = true;
            }
            break;
        case 2:
            firstIndex = idxFirstEmpty({x, y}, true);
            if (firstIndex == 0) { // 맨 시작 col 초기화됨
                for (int i=0; i<4; i++) {
                    blueBoard[i][blueStartCol] = false;
                    blueBoard[i][(blueStartCol - 1 + 4) % 4] = false;
                }
                blueBoard[x][blueStartCol] = true;
                blueBoard[x][(blueStartCol - 1 + 4) % 4] = true;
                blueStartCol = (blueStartCol + 2) % 4;
            }
            else if (firstIndex == 1) { // 맨 시작 col 초기화됨
                for (int i=0; i<4; i++) {
                    blueBoard[i][blueStartCol] = false;
                }
                blueBoard[x][blueStartCol] = true;
                blueBoard[x][(blueStartCol + 1) % 4] = true;

                blueStartCol = (blueStartCol - 1 + 4) % 4;
            }
            else {
                blueBoard[x][(blueStartCol + firstIndex) % 4] = true;
                blueBoard[x][(blueStartCol + firstIndex - 1 + 4) % 4] = true;
            }
            break;
        case 3:
            firstIndex = min(idxFirstEmpty({x, y}, true), idxFirstEmpty({x+1, y}, true));
            if (firstIndex == 0) { // 맨 시작 col 초기화됨
                for (int i = 0; i < 4; i++) {
                    blueBoard[i][blueStartCol] = false;
                }
                blueBoard[x][blueStartCol] = true;
                blueBoard[x + 1][blueStartCol] = true;
                blueStartCol = (blueStartCol - 1 + 4) % 4;
            }
            else {
                blueBoard[x][(blueStartCol + firstIndex) % 4] = true;
                blueBoard[x + 1][(blueStartCol + firstIndex) % 4] = true;
            }
            break;
    }
    blueCheck();
}

void runGreen(const cmd& command) {
    int t = command._t;
    int x = command._x;
    int y = command._y;
    int firstIndex;
    
    // 블럭 놓은 로직
    switch (t) {
        case 1:
            firstIndex = idxFirstEmpty({x, y}, false);
            if (firstIndex == 0) { // 맨 시작 row 초기화됨
                for (int i = 0; i < 4; i++) {
                    greenBoard[greenStartRow][i] = false;
                }
                greenBoard[greenStartRow][y] = true;
                greenStartRow = (greenStartRow - 1 + 4) % 4;
            }
            else {
                greenBoard[(greenStartRow + firstIndex) % 4][y] = true;
            }
            break;
        case 2:
            firstIndex = min(idxFirstEmpty({x, y}, false), idxFirstEmpty({x, y+1}, false));
            if (firstIndex == 0) { // 맨 시작 row 초기화됨
                for (int i=0; i<4; i++) {
                    greenBoard[greenStartRow][i] = false;
                }
                greenBoard[greenStartRow][y] = true;
                greenBoard[greenStartRow][y + 1] = true;

                greenStartRow = (greenStartRow - 1 + 4) % 4;
            }
            else {
                greenBoard[(greenStartRow + firstIndex) % 4][y] = true;
                greenBoard[(greenStartRow + firstIndex) % 4][y + 1] = true;
            }
            break;
        case 3:
            firstIndex = idxFirstEmpty({x, y}, false);
            if (firstIndex == 0) { // 맨 시작 row 초기화됨
                for (int i=0; i<4; i++) {
                    greenBoard[greenStartRow][i] = false;
                    greenBoard[(greenStartRow - 1 + 4) % 4][i] = false;
                }
                greenBoard[greenStartRow][y] = true;
                greenBoard[(greenStartRow - 1 + 4) % 4][y] = true;

                greenStartRow = (greenStartRow + 2) % 4;
            }
            else if (firstIndex == 1) { // 맨 시작 row 초기화됨
                for (int i=0; i<4; i++) {
                    greenBoard[i][blueStartCol] = false;
                }
                greenBoard[greenStartRow][y] = true;
                greenBoard[(greenStartRow + 1) % 4][y] = true;

                greenStartRow = (greenStartRow - 1 + 4) % 4;
            }
            else {
                greenBoard[(greenStartRow + firstIndex) % 4][y] = true;
                greenBoard[(greenStartRow + firstIndex - 1 + 4) % 4][y] = true;
            }
            break;
    }

    // 블럭에 의해 한 line 이 만들어 졌을 경우..
    greenCheck();
}

void run() {
    for (auto& c : cmds) {
        runBlue(c);
        runGreen(c);

/*
        cout << "test" << endl << "BLUE : " << blueStartCol << endl;
        for (int  i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                cout << blueBoard[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << "GREEN : " << greenStartRow << endl;
        for (int  i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                cout << greenBoard[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
*/
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (greenBoard[i][j])  boardCnt++;
            if (blueBoard[i][j])  boardCnt++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i=0, t, x, y; i < n; i++) {
        cin >> t >> x >> y;
        cmds.emplace_back(t, x, y);
    }

    run();

    cout << score << "\n" << boardCnt;

    return 0;
}
