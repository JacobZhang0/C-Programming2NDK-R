#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(void)
{
    int test = binsearch(20, (int[]) {5,6,10,23}, 4);
    printf("%d", test);
    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (x > v[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (low < n && v[low] == x)
        return low;

    return -1;
}
