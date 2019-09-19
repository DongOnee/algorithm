#include <cstdio>

int inorder[100001], postorder[100001];
int idxPost[100001], idxIn[100001];
int n;

void preorderFunc(int idxStartIn, int idxStartPost, int cnt)
{
    if (cnt < 1) return;

    int valRoot = postorder[idxStartPost + cnt -1];
    printf("%d ", valRoot);

    int idxRoot = idxIn[valRoot];
    int leftSize = idxRoot - idxStartIn;
    preorderFunc(idxStartIn, idxStartPost, leftSize);
    preorderFunc(idxRoot+1, idxStartPost + leftSize, cnt - leftSize -1);
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) 
    {
        scanf("%d", inorder + i);
        idxIn[inorder[i]] = i;
    }
    for (int i=0; i<n; i++) 
    {
        scanf("%d", postorder + i);
        idxPost[postorder[i]] = i;
    }

    preorderFunc(0, 0, n);

    return 0;
}
