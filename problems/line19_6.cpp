#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<char>> map;
int maxWidth, alignValue;
vector<int> orders;
int widths[10];

char printNums[10][5][3] = {
    { {'#', '#', '#'}, {'#', '.', '#'}, {'#', '.', '#'}, {'#', '.', '#'}, {'#', '#', '#'}},
    { {'.', '.', '#'}, {'.', '.', '#'}, {'.', '.', '#'}, {'.', '.', '#'}, {'.', '.', '#'}},
    { {'#', '#', '#'}, {'.', '.', '#'}, {'#', '#', '#'}, {'#', '.', '.'}, {'#', '#', '#'}},
    { {'#', '#', '#'}, {'.', '.', '#'}, {'#', '#', '#'}, {'.', '.', '#'}, {'#', '#', '#'}},
    { {'#', '.', '#'}, {'#', '.', '#'}, {'#', '#', '#'}, {'.', '.', '#'}, {'.', '.', '#'}},
    { {'#', '#', '#'}, {'#', '.', '.'}, {'#', '#', '#'}, {'.', '.', '#'}, {'#', '#', '#'}},
    { {'#', '.', '.'}, {'#', '.', '.'}, {'#', '#', '#'}, {'#', '.', '#'}, {'#', '#', '#'}},
    { {'#', '#', '#'}, {'.', '.', '#'}, {'.', '.', '#'}, {'.', '.', '#'}, {'.', '.', '#'}},
    { {'#', '#', '#'}, {'#', '.', '#'}, {'#', '#', '#'}, {'#', '.', '#'}, {'#', '#', '#'}},
    { {'#', '#', '#'}, {'#', '.', '#'}, {'#', '#', '#'}, {'.', '.', '#'}, {'.', '.', '#'}}
};

// string printNums[10][5] = {
//     { "###", "#.#", "#.#", "#.#", "###"},
//     { "..#", "..#", "..#", "..#", "..#"},
//     { "###", "..#", "###", "#..", "###"},
//     { "###", "..#", "###", "..#", "###"},
//     { "#.#", "#.#", "###", "..#", "..#"},
//     { "###", "#..", "###", "..#", "###"},
//     { "#..", "#..", "###", "#.#", "###"},
//     { "###", "..#", "..#", "..#", "..#"},
//     { "###", "#.#", "###", "#.#", "###"},
//     { "###", "#.#", "###", "..#", "..#"}
// };

int main(int argc, char const *argv[])
{
    int cntCmd, totalWidth = 9;
    char tmpAlign[10];
    scanf("%d %s", &cntCmd, tmpAlign);
    if (strcmp(tmpAlign, "TOP") == 0) alignValue = 0;
    else if (strcmp(tmpAlign, "MIDDLE") == 0) alignValue = 1;
    else if (strcmp(tmpAlign, "BOTTOM") == 0) alignValue = 2;

    for (int i=0; i<cntCmd; i++)
    {
        int lineSize;
        char tmpNums[11];
        scanf("%d %s", &lineSize, tmpNums);

        int idx = -1;
        while (tmpNums[++idx] != '\0')
        {
            orders.push_back(tmpNums[idx]-'0');
            widths[tmpNums[idx]-'0'] = lineSize;
            totalWidth += lineSize;
        }

        maxWidth = (maxWidth>lineSize?maxWidth:lineSize);
    }

    map.assign(2*maxWidth-1, vector<char>(totalWidth, ' '));

    int startCol = 0;
    for (int num : orders)
    {
        int width = widths[num];
        int height = 2*width -1;

        int startRow = 2*maxWidth-1 - height;
        if (alignValue == 0) startRow = 0;
        else if (alignValue == 1) startRow /= 2;

        for (int r = 0; r<2*maxWidth-1; r++) for (int c = 0; c<width; c++) map[r][c+startCol] ='.';

        for (int r = 0, idxRow; r < height; r++)
        {
            if (r == 0) idxRow = 0;
            else if (r < width -1) idxRow = 1;
            else if (r == width -1) idxRow = 2;
            else if (r < 2*width -2) idxRow = 3;
            else idxRow = 4;

            for (int c = 0, idxCol; c < width; c++)
            {
                if (c == 0) idxCol = 0;
                else if (c < width-1) idxCol = 1;
                else idxCol = 2;

                map[startRow + r][startCol + c] = printNums[num][idxRow][idxCol];
                // printf("map[%d][%d] = %c\n", startRow + r, startCol + c, map[startRow + r][startCol + c]);
            }
        }

        startCol += width +1;
    }

    for ( vector<char> x : map)
    {
        for (char y : x ) printf("%c", y);
        printf("\n");
    }

    return 0;
}


/*
4 BOTTOM
7 123
5 56
3 789
5 40
*/