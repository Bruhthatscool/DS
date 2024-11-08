// Program to sort an array using Heap Sort
// array[1:size]

#include<stdio.h>
#include<math.h>

// declare size of array and heap size as global
int size, heapsize;

// function to find the left child of ith element
int lchild(int i)
{
    return 2*i;
}

// function to find the right child of ith element
int rchild(int i)
{
    return 2*i+1;
}

// function to swap two items
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// to heapify subtree with root i
void heapify(int a[50], int i)
{
	// initialize largest as root
    int l = lchild(i), r = rchild(i), largest = i;
    
	// if left child is larger than root
    if(l <= heapsize && a[l] > a[largest])
    {
        largest = l;
    }
	
	// if right child is larger than largest so far
    if(r <= heapsize && a[r] > a[largest])
    {
        largest = r;
    }
    
	// if largest is not root
    if(largest != i)
    {
        swap(&a[i], &a[largest]);
		// recursively heapify the subtree
        heapify(a, largest);
    }
}

// function to build heap(rearrange array)
void buildHeap(int a[50])
{
    int i;
    heapsize = size;
    
    for(i = size/2; i > 0; i--)
    {
        heapify(a, i);
    }
}

// Main function to do heap sort
void heapSort(int a[50])
{
    int i;
    buildHeap(a);
    
    for(i = size; i > 1; i--)
    {
		// bring largest elements to the end
        swap(&a[1], &a[i]);

		// heapify the reduced heap
        heapsize--;
        heapify(a, 1);
    }
}

void main()
{
    int a[50], i;
    printf("Enter size of array : ");
    scanf("%d", &size);
    
	// input unsorted array
    printf("Enter %d elements : ", size);
    for(i = 1; i <= size; i++)
    {
        scanf("%d", &a[i]);
    }
    
	// calling heapSort function
    heapSort(a);
    
	// display sorted array
    printf("\nSorted : ");
    for(i = 1; i <= size; i++)
    {
        printf("%d", a[i]);
    }
}
