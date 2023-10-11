#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,n,temp,mid_index,min;
    int a[20];
    printf("Enter the no of terms:");
    scanf("%d",&n);
    printf("\n Enter the elements in array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n Array before sorting:");
 for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        min=a[i];
        mid_index=i;
        for(j=(i+1);j<n;j++)
        {
            if(a[j]<min)
            {
                min=a[j];
                mid_index=j;
            }
        }
        if(mid_index!=i)
        {
            temp=a[i];
            a[i]=a[mid_index];
            a[mid_index]=temp;
        }
    }//end of loop
    printf("\n Array after  sorting:");
     for(i=0;i<n;i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}