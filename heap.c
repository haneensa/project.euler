#include <stdio.h>

void swap(int *, int *);
int parent(int);
int left(int);
int right(int);
void build_max_heap(int A[]);
void bubble_down_max(int A[], int);
void bubble_up_max(int A[], int);
void max_heap_insert(int A[], int);
int max_extract(int A[]);
void heap_sort_max(int A[]);

int main(int argc, char *argv[])
{
	int A[] = {10, 10, 9, 4, 5, 2, 1, 8, 7, 3, 6};
	int i;

	printf("left child of %d, is  A[%d] = %d \n", A[1], left(1), A[left(1)]);
	printf("Before heapifying\n");
	for (i = 0; i <= A[0]; i++) {
		printf("A[%d] = %d \n", i, A[i]);
	}

	printf("After heapifying\n");
	build_max_heap(A);
	for (i = 0; i <= A[0]; i++) {
		printf("A[%d] = %d \n", i, A[i]);
	}
	printf("parent of %d, is  A[%d] = %d \n", A[2], parent(2), A[parent(2)]);
	printf("parent of %d, is  A[%d] = %d \n", A[3], parent(3), A[parent(3)]);
	printf("parent of %d, is  A[%d] = %d \n", A[4], parent(4), A[parent(4)]);
	printf("parent of %d, is  A[%d] = %d \n", A[5], parent(5), A[parent(5)]);
	printf("parent of %d, is  A[%d] = %d \n", A[6], parent(6), A[parent(6)]);
	printf("Test extraction\n");
	int key = max_extract(A);
	printf("Number of elements in the heap is: %d\n", A[0]);
	printf("The extracted element is: %d\n", key);
	for (i = 0; i <= A[0]; i++) {
		printf("A[%d] = %d \n", i, A[i]);
	}
	heap_sort_max(A);
	printf("After sorting\n");
	int length = sizeof(A)/sizeof(A[0]);
	printf("length of array is %d\n", length);
	for (i = 0; i < length - 1; i++) {
		printf("A[%d] = %d \n", i, A[i]);
	}

	return 0;
}
/* swapping numbers using call by reference */
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}

int parent(int i)
{
	if (i == 0)	// This holds the size of the heap
		return -1;
	if (i == 1)	// Root, no parent
		return 1;
	return i/2;
}

int left(int i)
{
	return 2 * i;
}

int right(int i)
{
	return 2 * i + 1;
}
	
void build_max_heap(int A[])
{
	int i;
	int hsize = A[0];
	/* Elements A[n/2+1 ... n] are all leaves of the tree */
	for (i = hsize/2; i > 0; i--) {
		bubble_down_max(A, i);
	}
}

void bubble_down_max(int A[], int i)
{
	int l = left(i);
	int r = right(i);
	int max = i;
	/* This means, if left didn't surpass the heap size and
	* left child is larger than it's parent
	*/
	if ((l <= A[0]) && (A[l] > A[max]))
		max = l;
	if ((r <= A[0]) && (A[r] > A[max]))
		max = r;
	
	if (max != i) {
		swap(&A[i], &A[max]);
		bubble_down_max(A, max);
	}
	
}

void bubble_up_max(int A[], int i)
{
	int p = parent(i);
	if (p == -1 || p == 1)
		return;
	if (p < A[i]) {
		swap(&A[p], &A[i]);
		bubble_up_max(A, p);
	}
}

void max_heap_insert(int A[], int)
{
	// Insert at end of the heap
	// bubble up till you find proper place

}
int max_extract(int A[])
{
	int hsize = A[0];
	
	if (hsize < 1) {
		printf("ERROR: Heap underflow\n");
		return -1;
	}

	int max = A[1];
	A[1] = A[hsize];
	A[0] -= 1;
	bubble_down_max(A, 1);
	
	return max;
}

void heap_sort_max(int A[]) {
	build_max_heap(A);
	int i, lenght = A[0];
	for (i = lenght; i > 0; i--) {
		swap(&A[1], &A[i]);
		A[0] -= 1;
		bubble_down_max(A, 1); 
	}
}

