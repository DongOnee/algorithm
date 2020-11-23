#include <iostream>
#include <vector>

using namespace std;

typedef
struct
{
    int type;
    int x;
    int y;
}block;

int blockCnt, score;
int boardBlue[4][20'003], boardGreen[20'003][4];
int botBlue = 20'002, botGreen = 20'002;

block blocks[10'001];
bool isSingleBlue[20'001], isSingleGreen[20'001];

int findEmpty(int topIndex, int standard, bool isBlue)
{
    int emptyIndex = topIndex;
    if (isBlue)
    {
        while (emptyIndex != botBlue)
        {
            if (boardBlue[standard][emptyIndex + 1] != 0) break;
            emptyIndex++;
        }
    }
    else
    {
        while (emptyIndex != botGreen)
        {
            if (boardGreen[emptyIndex + 1][standard] != 0) break;
            emptyIndex++;
        }
    }
    
    return emptyIndex;
}

void insertBlock(int blockIndex)
{
    // Blue
    {
        if (blocks[blockIndex].type == 1)
        {
            isSingleBlue[blockIndex] = true;
            int emptyIndex = findEmpty(botBlue - 5, blocks[blockIndex].x, true);
            boardBlue[blocks[blockIndex].x][emptyIndex] = blockIndex;
        }
        else if (blocks[blockIndex].type == 2)
        {
            int emptyIndex = findEmpty(botBlue - 5, blocks[blockIndex].x, true);
            boardBlue[blocks[blockIndex].x][emptyIndex] = blockIndex;
            boardBlue[blocks[blockIndex].x][emptyIndex - 1] = blockIndex;
        }
        else if (blocks[blockIndex].type == 3)
        {
            int emptyIndex = min(findEmpty(botBlue - 5, blocks[blockIndex].x, true), findEmpty(botBlue - 5, blocks[blockIndex].x + 1, true));
            boardBlue[blocks[blockIndex].x][emptyIndex] = blockIndex;
            boardBlue[blocks[blockIndex].x + 1][emptyIndex] = blockIndex;
        }
    }

    // Green
    {
        if (blocks[blockIndex].type == 1)
        {
            isSingleGreen[blockIndex] = true;
            int emptyIndex = findEmpty(botGreen - 5, blocks[blockIndex].y, false);
            boardGreen[emptyIndex][blocks[blockIndex].y] = blockIndex;
        }
        else if (blocks[blockIndex].type == 3)
        {
            int emptyIndex = findEmpty(botGreen - 5, blocks[blockIndex].y, false);
            boardGreen[emptyIndex][blocks[blockIndex].y] = blockIndex;
            boardGreen[emptyIndex - 1][blocks[blockIndex].y] = blockIndex;
        }
        else if (blocks[blockIndex].type == 2)
        {
            int emptyIndex = min(findEmpty(botGreen - 5, blocks[blockIndex].y, false), findEmpty(botGreen - 5, blocks[blockIndex].y + 1, false));
            boardGreen[emptyIndex][blocks[blockIndex].y] = blockIndex;
            boardGreen[emptyIndex][blocks[blockIndex].y + 1] = blockIndex;
        }

    }
}

void checkBoard(vector<int>& eraseList, bool isBlue)
{
    if (isBlue)
    {
        for (int i = 0; i < 4; i++)
        {
            if (boardBlue[0][botBlue - i]
             && boardBlue[1][botBlue - i]
             && boardBlue[2][botBlue - i]
             && boardBlue[3][botBlue - i])
                eraseList.push_back(botBlue - i);
        }
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (boardGreen[botGreen - i][0]
             && boardGreen[botGreen - i][1]
             && boardGreen[botGreen - i][2]
             && boardGreen[botGreen - i][3])
                eraseList.push_back(botGreen - i);
        }
    }
}

void eraseLine(vector<int> eraseList, bool isBlue)
{
    if (isBlue)
    {
        for (int col : eraseList)
        {
            for (int row = 0; row < 4; row++)
            {
                isSingleBlue[boardBlue[row][col]] = true;
                boardBlue[row][col] = 0;
            }
        }
    }
    else
    {
        for (int row : eraseList)
        {
            for (int col = 0; col < 4; col++)
            {
                isSingleGreen[boardGreen[row][col]] = true;
                boardGreen[row][col] = 0;
            }
        }
    }
}

void arrangeBoard(int index, bool isBlue)
{
    if (isBlue)
    {
        while (index > botBlue - 6)
        {
            for (int row = 0; row < 4; row++)
            {
                if (boardBlue[row][index] != 0)
                {
                    if (isSingleBlue[boardBlue[row][index]] || blocks[boardBlue[row][index]].type == 2)
                    {
                        int emptyCol = findEmpty(index, row, true);
                        boardBlue[row][emptyCol] = boardBlue[row][index];
                        boardBlue[row][index] = 0;
                    }
                    else
                    {
                        int emptyCol = min(findEmpty(index, row, true), findEmpty(index, row + 1, true));
                        boardBlue[row][emptyCol] = boardBlue[row][index];
                        boardBlue[row+1][emptyCol] = boardBlue[row+1][index];
                        boardBlue[row][index] = 0;
                        boardBlue[row+1][index] = 0;
                        row++;
                    }
                }
            }
            index--;
        }
    }
    else
    {
        while (index > botGreen - 6)
        {
            for (int col = 0; col < 4; col++)
            {
                if (boardGreen[index][col] != 0)
                {
                    if (isSingleGreen[boardGreen[index][col]] || blocks[boardGreen[index][col]].type == 3)
                    {
                        int emptyRow = findEmpty(index, col, false);
                        boardGreen[emptyRow][col] = boardGreen[index][col];
                        boardGreen[index][col] = 0;
                    }
                    else
                    {
                        int emptyRow = min(findEmpty(index, col, false), findEmpty(index, col + 1, false));
                        boardGreen[emptyRow][col] = boardGreen[index][col];
                        boardGreen[emptyRow][col+1] = boardGreen[index][col+1];
                        boardGreen[index][col] = 0;
                        boardGreen[index][col+1] = 0;
                        col++;
                    }
                }
            }
            index--;
        }
    }
}

void run(int blockIndex)
{
    insertBlock(blockIndex);

    // Blue
    while (true)
    {
        vector<int> eraseCol;
        checkBoard(eraseCol, true);

        if (eraseCol.empty()) break;
        score += eraseCol.size();
        eraseLine(eraseCol, true);
        arrangeBoard(eraseCol[0], true);
    }


    // Green
    while (true)
    {
        vector<int> eraseRow;
        checkBoard(eraseRow, false);

        if (eraseRow.empty()) break;
        score += eraseRow.size();
        eraseLine(eraseRow, false);
        arrangeBoard(eraseRow[0], false);
    }

    while (!(boardBlue[0][botBlue-4] == 0
          && boardBlue[1][botBlue-4] == 0
          && boardBlue[2][botBlue-4] == 0
          && boardBlue[3][botBlue-4] == 0)) botBlue--;

    while (!(boardGreen[botGreen-4][0] == 0
          && boardGreen[botGreen-4][1] == 0
          && boardGreen[botGreen-4][2] == 0
          && boardGreen[botGreen-4][3] == 0)) botGreen--;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> blockCnt;

    for (int i=1, t, x, y; i <= blockCnt; ++i)
    {
        cin >> t >> x >> y;
        blocks[i] = {t, x, y};
        run(i);
    }

    int blockCount = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j =  0; j < 4; j++)
        {
            if (boardBlue[i][botBlue-j] != 0) blockCount++;
            if (boardGreen[botGreen - i][j] != 0) blockCount++;
        }
    }

    cout << score << "\n" << blockCount << "\n";

    return 0;
}
