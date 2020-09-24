#include <stdio.h>
#include <stdlib.h>
void display_menu();
void get_input(int**,int*);
void display_array(const int*, int size);
void insert_element(int**,int*);
void delete_element(int**,int*);
int main()
{
	int *arr;
	arr=NULL;
	int n=0;
	int choice;
//	display_menu();
	do{
		display_menu();
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: get_input(&arr,&n);
					break;
			case 2: 
						display_array(arr,n);
//						printf("No elements to display-ARRAY IS EMPTY\n");
//					
//						printf("The array elements are:\n");
//						for(int i=0;i<n;++i)
//							printf("%d\t",arr[i]);
//						printf("\n");
//					
					break;
			case 3: insert_element(&arr, &n);
					break;
			case 4: delete_element(&arr,&n);
					break;
			case 5: printf("Good bye...\n");
					break;
			default: printf("Invalid input-try again\n");
		}
	}while(choice!=5);
	free(arr);
	return 0;
}
void display_menu(){
	printf("1. Create an array\t2. Display array\t3. Insert\t4. Delete\t5. Exit\n");
}
void display_array(const int *arr, int size){
	if(size==0)
		printf("No elements to display-ARRAY IS EMPTY\n");
	else{
		printf("The array elements are:\n");
		for(int i=0;i<size;++i)
			printf("%d\t",arr[i]);
		printf("\n");
	}
}
void get_input(int **a, int* n){
	printf("Enter number of elements: ");
	scanf("%d",n);
	*a=(int*)calloc(*n,sizeof(int));
		printf("Enter array elements: ");
		for(int i=0;i<*n;++i)
			scanf("%d",&(*a)[i]);
}
void insert_element(int **a,int *n){
	int idx, e=0;
	printf("Enter the position at which you want to insert the element: ");
	scanf("%d",&idx);
	if(idx<1 || idx>*n+1)
		printf("Invalid input- position must be from 1 to %d\n",(*n)+1);
	else{
		*a=(int*)realloc(*a,(*(n)+1)*sizeof(int));
		printf("Enter the element to be inserted: ");
		scanf("%d",&e);
		for(int i=*n;i>idx-1;i--)
			(*a)[i]=(*a)[i-1];
		(*a)[idx-1]=e;
		(*n)++;
		printf("Element inserted\n");
	}

}
void delete_element(int **a,int *n){
	if(*n==0)
		printf("Can't delete elements from an empty array\n");
	else{
		int idx;
		printf("Enter the position from which element has to be deleted: ");
		scanf("%d",&idx);
		if(idx<1 || idx>*n)
		
			printf("Invalid input- position must be from 1 to %d\n",(*n));
		else{
			for(int i=idx-1;i<(*n)-1;i++)
				(*a)[i]=(*a)[i+1];
			(*a)[*n-1]=0;
			(*n)--;
		}
		printf("Element deleted\n");
	}
}
