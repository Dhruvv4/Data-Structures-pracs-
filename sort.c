#include <stdio.h>
 
void bubble_sort(int [], int);
 
int main()
{
  int array[100], n, i, j, swap,choice;
 
  printf("Enter number of elements\n");
  scanf("%d", &n);
 
  printf("Enter %d integers\n", n);
 
  for (i = 0; i < n; i++)
	scanf("%d", &array[i]);
 
  printf("Enter your choice:\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n4.Exit\n");
  scanf("%d",&choice);

  while(choice != 4){

  	switch(choice){
  		case 1: bubble_sort(array, n);
 
  		printf("Sorted list in ascending order:\n");
 
 		for ( i = 0 ; i < n ; i++ )
		printf("%d\n", array[i]);
  		}
  		break;

  		case 2: 
  }
 
  return 0;
}
 
void bubble_sort(int list[], int n)
{
  int i, j, t;
 
  for (i = 0 ; i < ( n - 1 ); i++)
  {
	for (j = 0 ; j < n - i - 1; j++)
	{
	  if (list[j] > list[j+1])
	  {

 
		t         = list[j];
		list[j]   = list[j+1];
		list[j+1] = t;
	  }
	}
  }
}