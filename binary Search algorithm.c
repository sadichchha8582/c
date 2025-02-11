#include<stdio.h>
int binarySearch(int arr[],int left,int right,int target)
{
    if (left>right)
    {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] = target)
    {
        return mid;
    }
    if (arr[mid] > target)
    {
        return binarySearch(arr,left,mid-1,target);
    }
    return binarySearch(arr,mid+1,right,target);
}

int main()
{
    int arr[] = {10,24,35,47,56,78,90,57,29,30};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target;
    printf("Enter the number to search:");
    int n;
    scanf("%d",& target);
    int result = binarySearch(arr,0,size-1,target);
    if(result!=-1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found \n");
    }
    return 0;
    
}
