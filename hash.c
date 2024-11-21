#include<stdio.h>
#include<stdlib.h>

int linear(int val, int arr[], int size)
{
    int i = val % size;
    if(arr[i] == -1)
    {
        arr[i] = val;
        printf("Index = %d %% %d = %d\n", val, size, i);
        printf("%d inserted at %d\n", val, i);
    }
    else
    {
        printf("Collision!!\n");
        printf("Index = (%d + 1) %% %d = %d\n", i, size, (i + 1) % size);
        i = (i + 1) % size;
        while (arr[i] != -1)
        {
            printf("Collision!!\n");
            printf("Index = (%d + 1) %% %d = %d\n", i, size, (i + 1) % size);
            i = (i + 1) % size;
        }
        arr[i] = val;
        printf("%d inserted at %d\n", val, i);
    }
    printf("\nLinear:\n");
    for(int a=0; a<size; a++)
    {
        printf("Index %d = %d\n", a, arr[a]);
    }
    return i;
}

int db(int val, int arr[], int size)
{
    int i = val % size;
    int hash = 5 - (val % 5);
    if(arr[i] == -1)
    {
        arr[i] = val;
        printf("Index = %d %% %d = %d\n", val, size, val % size);
        printf("%d inserted at index %d\n", val, i);
    }
    else
    {
        printf("Collision!!\n");
        int j = 1;
        printf("hash = 5 - (%d %% 5)",val);
        printf("Index = (%d %% %d) + %d*hash",val,size,j);
        i = (val % size + j * hash) % size;
        while (arr[i] != -1)
        {
            printf("Collision!!\n");
            j++;
            i = (val % size + j * hash) % size;
        }
        arr[i] = val;
        printf("%d inserted at %d\n", val, i);
    }
    printf("\nDouble:\n");
    for(int a=0; a<size; a++)
    {
        printf("Index %d = %d\n", a, arr[a]);
    }
    return i;
}

int quadratic(int val, int arr[], int size)
{
    int i = val % size;
    int k = 1;
    if(arr[i] == -1)
    {
        arr[i] = val;
        printf("Index = %d %% %d = %d\n", val, size, i);
        printf("%d inserted at %d\n", val, i);
    }
    else
    {
        printf("Collision!!\n");
        i = (i + k * k) % size;
        printf("Index = (%d + %d^2) %% %d = %d\n", (val % size), k, size, i);
        while (arr[i] != -1)
        {
            k++;
            i = (val % size + k * k) % size;
            printf("Collision!!\n");
            printf("Index = (%d + %d^2) %% %d = %d\n", (val % size), k, size, i);
        }
        arr[i] = val;
        printf("%d inserted at %d\n", val, i);
    }
    printf("\nQuadratic:\n");
    for(int a=0; a<size; a++)
    {
        printf("Index %d = %d\n", a, arr[a]);
    }
    return i;
}

int main()
{
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);
    int hashlin[size];
    int hashd[size];
    int hashquad[size];
    for(int i=0; i<size; i++)
    {
        hashlin[i] = -1;
        hashd[i] = -1;
        hashquad[i] = -1;
    }
    int a = 1;
    int index;
    while(a == 1)
    {
        int choice, val1, val2, val3;
        printf("1) Linear\n2) Double\n3) Quadratic\n4) Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: 
                printf("Enter the value: ");
                scanf("%d", &val1);
                index = linear(val1, hashlin, size);
                hashlin[index] = val1;
                break;
                
            case 2: 
                printf("Enter the value: ");
                scanf("%d", &val2);
                index = db(val2, hashd, size);
                hashd[index] = val2;
                break;
                
            case 3: 
                printf("Enter the value: ");
                scanf("%d", &val3);
                index = quadratic(val3, hashquad, size);
                hashquad[index] = val3;
                break;
                
            case 4: 
                a++;
                break;
            
            default: 
                printf("Enter a correct value\n");
        }
    }
    return 0;
}
