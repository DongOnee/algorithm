#include <cstdio>
using namespace std;

#define HEADIDX 0
#define TAILIDX 600002

typedef struct
{
    char input;
    int idxPrev;
    int idxNext;
} node;

node arr[600003];
int cntArr;

void deleteFunc(int idxCur)
{
    int idxPrev1 = arr[idxCur].idxPrev;
    int idxNext1 = arr[idxCur].idxNext;

    arr[idxPrev1].idxNext = idxNext1;
    arr[idxNext1].idxPrev = idxPrev1;
}

int main(int argc, char const *argv[])
{
    char initInput[100001];
    scanf("%s", initInput);

    while (char c = initInput[cntArr++])
    {
        arr[cntArr].input = c;
        arr[cntArr].idxPrev = cntArr-1;
        arr[cntArr].idxNext = cntArr+1;
    }

    arr[0].idxNext = 1;
    arr[cntArr-1].idxNext = TAILIDX;
    arr[TAILIDX].idxPrev = cntArr-1;
    int cntCmd, curIdx = TAILIDX;
    scanf("%d", &cntCmd);
    while (cntCmd--)
    {
        char cmd[3];
        scanf("%s", cmd);

        if (cmd[0] == 'L') curIdx = arr[curIdx].idxPrev==HEADIDX?curIdx:arr[curIdx].idxPrev;
        else if (cmd[0] == 'D') curIdx = curIdx==TAILIDX?curIdx:arr[curIdx].idxNext;
        else if (cmd[0] == 'B')
        {
            if (arr[curIdx].idxPrev != HEADIDX) deleteFunc(arr[curIdx].idxPrev);
        }
        else if (cmd[0] == 'P')
        {
            char cmd2[2];
            scanf("%s", cmd2);
            
            arr[cntArr].input = cmd2[0];

            arr[cntArr].idxPrev = arr[curIdx].idxPrev;
            arr[cntArr].idxNext = curIdx;

            arr[arr[curIdx].idxPrev].idxNext = cntArr;
            arr[curIdx].idxPrev = cntArr;

            cntArr++;
        }
    }

    int idxSearch = arr[HEADIDX].idxNext;
    while (idxSearch != TAILIDX)
    {
        printf("%c", arr[idxSearch].input);
        idxSearch = arr[idxSearch].idxNext;
        // printf("\tSearch Index : %d\n", idxSearch);
        // printf("arr[%d]:%c\nidxPrev:%d\nidxNext:%d\n", idxHead, arr[idxHead].input, arr[idxHead].idxPrev, arr[idxHead].idxNext);
    }
    
    return 0;
}
