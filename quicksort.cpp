#include <iostream>
#include <ctime>
using namespace std;

int partition(int* A, int p, int r)
{
	int x = A[r];
	int i = p - 1;
	int aux = 0;

	for (int j = p; j <= r - 1; j++) {
		if (A[j] <= x)
		{
			i++;
			aux = A[i];
			A[i] = A[j];
			A[j] = aux;
		}
	}
	aux = A[i + 1];
	A[i + 1] = A[r];
	A[r] = aux;
	
	return i + 1;
}
void quicksort(int* A, int p, int r)
{
	int q = 0;
	if (p < r)
	{
		q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
	}
}
void randomise(int* A, int n)
{
	srand(time(NULL));
	for (int i = 0; i <= n; i++)
		A[i] = rand() % 100 + 1;
}
void print(int* A, int n)
{
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
}

int main()
{
	int n = 50;
	int* A = (int*)malloc((n+1) * sizeof(int));
	randomise(A, n);
	quicksort(A, 0, n);
	print(A, n);

}