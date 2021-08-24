#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

#define N 100

void fill_from_one(int tab[]);
void show_array(int tab[]);
void unsort_array(int tab[]);
void rand_array(int tab[]);
void swap(int tab[], int a, int b);
int max(int tab[]);
void arr_zero(int tab[], int length);
void unscramble_backwards(int tab[]);

void comb_sort(int tab[]);
void insertion_sort(int tab[]);
void counting_sort(int tab[]);

int main()
{
	int *tab = (int*)malloc(N * sizeof(int*));
	double* arr = (double*)malloc(N * sizeof(double));

	puts("unsorted array");
	srand(time(0));
	rand_array(tab);
	show_array(tab);

	puts("\n");

	puts("\ncomb sort");
	comb_sort(tab);
	show_array(tab);
	///
	puts("\nrandomising array...\n");
	srand(time(0));
	rand_array(tab);

	puts("\ninsertion sort");
	insertion_sort(tab);
	show_array(tab);
	///
	puts("\nrandomising array...\n");
	srand(time(0));
	rand_array(tab);

	puts("\ncounting sort");
	counting_sort(tab);
	show_array(tab);


	printf("\n");
	system("pause");

	return 0;
}

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

void rand_array(int tab[])
{
	int i = 0;
	for (int i = 0; i < N; i++) {

		tab[i] = rand() % N;
	}
}

void show_array(int tab[])
{
	int i = 0;
	for (i = 0; i < N; i++) {

		printf("%d ", tab[i]);
	}
}

void insertion_sort(int tab[])
{
	int i = 0, j = 0;

	for (i = 1; i < N; i++) {

		for (j = i; j > 0; j--) {

			if (tab[j] < tab[j - 1]) swap(tab, j, j - 1);
			else if (tab[j] > tab[j - 1]) break;
		}
	}
}

void swap(int tab[], int a, int b)
{
	int x = tab[a];
	tab[a] = tab[b];
	tab[b] = x;
}

void fill_from_one(int tab[])
{
	int i = 0;
	for (i = 0; i < N; i++) {

		tab[i] = i + 1;
	}
}

void unsort_array(int tab[])
{
	int i = 0;
	for (i = 0; i < N; i++) {
		swap(tab, rand() % (N), rand() % (N));
	}
}

void counting_sort(int tab[])
{
	int* aux = (int*)malloc((max(tab) + 1)*(sizeof(int)));
	int i = 0, j = 0, x = 0;

	arr_zero(aux, max(tab) + 1);

	for (i = 0; i < N; i++) {

		aux[tab[i]]++;
	}

	x = N - 1;
	for (i = max(tab); i >= 0; i--) {

		while (aux[i] != 0) {

			tab[x] = i;

			x--;
			aux[i]--;
		}
	}

}

int max(int tab[])
{
	int max = tab[0];
	int i = 0;
	for (i = 1; i < N; i++) {

		if (tab[i] > max) max = tab[i];
	}

	return max;
}

void arr_zero(int tab[], int l)
{
	int i = 0;
	for (i = 0; i < l; i++) {

		tab[i] = 0;
	}
}

void unscramble_backwards(int tab[])
{
	int i = 0;
	for (i = 0; i < N / 2; i++) {

		swap(tab, i, N - 1 - i);
	}
}

void comb_sort(int tab[])
{
	int x = N;
	int i = 0;
	int bool_aux = 1;

	while (x > 1 || bool_aux == 1) {

		x /= 1.3;

		if (x == 1) bool_aux = 0;

		for (i = 0; i + x < N; i++) {

			if (tab[i] > tab[i + x]) swap(tab, i, i + x);
		}
	}

}