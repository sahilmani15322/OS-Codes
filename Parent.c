#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>

void bubblesort(int *arr,int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp; 
			}
		}
	}
}

int main()
{
	int n;
	printf("Enter the size of array : ");
	scanf("%d",&n);
	int *arr = (int *)malloc(n*sizeof(int));
	printf("Enter the values of array : ");
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	/*
	for(i=0;i<n;i++)
	{
		printf("\n%d",arr[i]);
	}
	*/

	bubblesort(arr,n);
	printf("The sorted array is : ");
	for(i=0;i<n;i++)
	{
		printf("\t%d",arr[i]);
	}

	char *str[20], buff[20];
	for(i=0;i<n;i++)
	{
		snprintf(buff,20,"%d",arr[i]);
		str[i+1] = strdup(buff);	
	}

	str[0] = malloc(10);
	strcpy(str[0],"child");
	str[n+1] = NULL;
	execv("./child",str);
	_exit(0);
	return 0;

}
