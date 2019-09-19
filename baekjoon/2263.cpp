#include <cstdio>
#include <vector>
using namespace std;

int inorder[100001], postorder[100001];
int idxPost[100001], idxIn[100001];
bool isChild[100001];
int n;

void preorderFunc(int idxStart, int count)
{
    if (count == 0) return;
    int idxMax = idxStart, valMax = idxIn[idxStart];
    for (int i=1; i<count; i++)
    {
        if (valMax < idxIn[idxStart+i])
        {
            idxMax = idxStart+i;
            valMax = idxIn[idxMax];
        }
    }
    printf("%d ", postorder[valMax]);
    preorderFunc(idxStart, idxMax - idxStart);
    preorderFunc(idxMax+1, count - idxMax + idxStart-1);
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", inorder+i);
    for (int i=0; i<n; i++)
    {
        scanf("%d", postorder+i);
        idxPost[postorder[i]] = i;
    }
    for (int i=0; i<n; i++)
    {
        idxIn[i] = idxPost[inorder[i]];
    }

    preorderFunc(0, n);


    return 0;
}
