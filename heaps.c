#include<stdio.h>
int s = 2;
int a = 2;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printing(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d, ",arr[i]);
    }
    printf("\n");
}

void max_heapify(int arr[], int n, int i)
{
    int l = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left<n && arr[left]>arr[l])
    {
        l = left;
    }

    if(right<n && arr[right]>arr[l])
    {
        l = right;
    }

    if(l!=i)
    {
        printf("Max-Heapify part:\n");
        printf("Swapping %d and %d\n",arr[l], arr[i]);
        swap(&arr[l], &arr[i]);
        printing(arr, n);
        max_heapify(arr, n, l);
    }
}

void min_heapify(int arr[], int n, int i)
{
    int l = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left<n && arr[left]<arr[l])
    {
        l = left;
    }

    if(right<n && arr[right]<arr[l])
    {
        l = right;
    }

    if(l!=i)
    {
        printf("Min-Heapify part:\n");
        printf("Swapping %d and %d\n",arr[l], arr[i]);
        swap(&arr[l], &arr[i]);
        printing(arr, n);
        min_heapify(arr, n, l);
    }
}

void max_heapsort(int arr[], int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        max_heapify(arr, n, i);
    }

    for(int i=n-1;i>0;i--)
    {
        printf("\nStep = %d\n",s);
        s++;
        printf("Max-Sorting part: \n");
        printing(arr, n);
        printf("Root %d swapped with %d\n",arr[0], arr[i]);
        swap(&arr[0], &arr[i]);
        printing(arr, n);
        max_heapify(arr, i, 0);
    }
}

void min_heapsort(int arr[], int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        min_heapify(arr, n, i);
    }

    for(int i=n-1;i>0;i--)
    {
        printf("\nStep = %d\n",a);
        a++;
        printf("Min-Sorting part: \n");
        printing(arr, n);
        printf("Root %d swapped with %d\n",arr[0], arr[i]);
        swap(&arr[0], &arr[i]);
        printing(arr, n);
        min_heapify(arr, i, 0);
    }
}

int main()
{
    printf("Max Heap\n");
    int n;
    printf("Enter the array size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Initial array is: ");
    printing(arr, n);
    printf("\nStep = 1\n");
    max_heapsort(arr, n);
    printf("Max-Heap Sorted array is: ");
    printing(arr, n);

    printf("\nMin Heap\n");
    printf("Enter the elements of array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Initial array is: ");
    printing(arr, n);
    printf("\nStep = 1\n");
    min_heapsort(arr, n);
    printf("Min-Heap Sorted array is: ");
    printing(arr, n);

    return 0;
}
