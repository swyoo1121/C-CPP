#include <iostream>

#define MAX 5000001

using namespace std;

int N, K;
int A[MAX];
int sorted[MAX];

void merge(int list[], int left, int mid, int right)
{
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right)
    {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    if (i > mid)
    {
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    }
    else
    {
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];
    }

    for (l = left; l <= right; l++)
    {
        list[l] = sorted[l];
    }
}

void merge_sort(int list[], int left, int right)
{
    int mid;

    if (left < right)
    {
        mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    for (int iter = 0; iter < N; iter++)
    {
        int input;
        cin >> input;
        A[iter] = input;
    }

    merge_sort(A, 0, N - 1);

    cout << A[K - 1] << endl;
    return 0;
}