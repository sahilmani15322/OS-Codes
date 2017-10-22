#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int binary(int arr[],int first, int end, int key)
{
	int mid;
	if(first<end)
	{
		mid = (first+end)/2 ;
		if(key == arr[mid])
			return mid;
		else if(key < arr[mid])
			return binary(arr,first,mid,key);
		else if(key > arr[mid])
			return binary(arr,mid+1,end,key);
	}
	if( (key < 0 ) || (key>end) )
		return -1;
}

int main(int argc , char *argv[])
{
	int i,j;
	int ch;
	int arr[50];
	int key,count;
	for(i=0;argv[i+1]!=NULL;i++)
	{
		arr[i] = atoi(argv[i+1]);
		count++;
	}
	printf("\nChild process Starts....\n ");
	for(i = 0;i<count;i++)
	printf("%d\t",arr[i]);
	printf("\nEnter the value to be searched : ");
	scanf("%d",&key);
	int t = binary(arr,0,count-1,key);
	if(t==-1)
		printf("Element is not present\n");
	else
	printf("%d is in %d position\n",key,t);
}

