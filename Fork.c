#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void merge(int arr[],int n)
{
	int i,j,k;
	int temp;
	int a1[50],a2[50];
	int n1,n2;
	if(n%2==0)
	{
		n1 = n2 = n/2;
	}
	else
	{
		n1 = n/2;
		n2 = n-n1;
	}

	for(i=0;i<n1;i++)
	{
		a1[i]=arr[i];
	}
	for(i=0;i<n2;i++)
	{
		a2[i]=arr[n1+i];
	}
	
	if(n1==2)
	{
		if(a1[0]>a1[1])	
		{
			temp = a1[0];
			a1[0] = a1[1];
			a1[1] = temp;	
		}
	}
	else if(n1>2)
		merge(a1,n1);

	if(n2==2)
	{
		if(a2[0]>a2[1])	
		{
			temp = a2[0];
			a2[0] = a2[1];
			a2[1] = temp;
		}
	}
	else if(n2>2)
		merge(a2,n2);

	i=j=k=0;

	while(i<n1 && j<n2)
	{
		if(a1[i]<=a2[j])
		{
			arr[k]=a1[i];
			i++;
			k++;
		}
		else if(a1[i]>a2[j])
		{
			arr[k]=a2[j];
			j++;
			k++;
		}
	}	
	
	while(i<n1)
	{
		arr[k] = a1[i];
		k++;
		i++;
	}

	while(j<n2)
	{
		arr[k] = a2[j];
		k++;
		j++;
	}
}

void quick(int arr[],int x,int y)
{
	int key ,i,j,temp;
	if(x<y)
	{
		key = arr[x];
		i = x;
		j = y;
		
		while(i<j)
		{
			while(key>=arr[i])
				i++;
			while(key<arr[j])
				j--;
			
			if(i<j)
			{
				temp = arr[i];	
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		temp = arr[x];
		arr[x] = arr[j];
		arr[j] = temp;


		quick(arr,x,j-1);
		quick(arr,j+1,y);
		
	}
}

int main()
{
	int arr[100],n;
	printf("Enter the size of array : ");
	scanf("%d",&n);
	printf("\nEnter the values of array : \n");
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("==============##===============\n");
	int a = fork();
	if(a==0)
	{
		printf("====Child Process====\n");
		//qsort(arr,0,n-1);
		printf("Quick Sort Algorithm : \n");
		quick(arr,0,n-1);
		printf("Sorted Algorithm : ");
		int i;
		for(i=0;i<n;i++)
			printf("%d\t",arr[i]);
	}
	else
	{
		printf("====Parent Process====\n");
		merge(arr,n);
		printf("merge Sort Algorithm : \n");
		printf("Sorted Algorithm : ");
		int i;
		for(i=0;i<n;i++)
			printf("%d\t",arr[i]);
		printf("\n");		
	}

}
