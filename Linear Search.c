#include<stdio.h>
int main()
{
    int i, j = 0, n, arr[100], search, isFound = 0, searchArr[10], count = 0;
    float freq;

    printf("Please enter the number of elements : ");
    scanf("%d", &n);

    printf("Please enter the numbers : \n");
    for (i = 0; i < n ;i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Please enter the value that you search for : ");
    scanf("%d", &search);
    for (i = 0; i < n ;i++)
    {
        if (search == arr[i])
        {
            j++;
            searchArr[j] = i+1;
            count++;
            isFound = 1;
        }
    }

    freq = ((float)j/(float)n)*100;
    int k = j;
    if (isFound)
    {
        for(k = 1; k <= j; k++)
        {
            printf("%d has found at %d position\n", search, searchArr[k]);
        }
        printf("The frequency of %d is %.2f", search, freq);

    } else
    {
        printf("%d not found", search);
    }

    return 0;
}