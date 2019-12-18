#include <cstdio>
#include <algorithm>
using namespace std;

int n, arr[1000];

int partition(int l, int r)
{
    int idx = l, pivot = arr[l];

    while (idx<r)
    {
        while (pivot < arr[r]) r--;
        while (idx < r && arr[idx] <= pivot) idx++;
        swap(arr[idx], arr[r]);
    }
    arr[l] = arr[idx];
    arr[idx] = pivot;

    return idx;
}

void quick(int l, int r)
{
    if (l >= r) return;

    int pivot = partition(l, r);

    for (int i=0; i<n; i++) printf("%2d ", arr[i]);
    printf("\n");
    for (int i=0; i<n; i++) printf("%s ", (i==pivot?"..":(l<=i&&i<=r?"--":"  ")));
    printf("\n");
    printf("\n");

    quick(l, pivot-1);
    quick(pivot+1, r);
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", arr+i);
    quick(0, n-1);
    for (int i=0; i<n; i++) printf("%d ", arr[i]);
    return 0;
}
/*
9
 3 44 38 47 5 15 36 26 27
*/