#define arraySize 100 /// размер массива
#define lineLenght 15 ///длина печатаемой строки в количестве элементов

#include <iostream>
#include <ctime>
using namespace std;
/**
@function swap
Перемена местами двух интовых чисел
*/
void swap(int *a, int *b)
{
	*a+=*b;
	*b=*a-*b;
	*a-=*b;
}
/**
@function merge_sort
Сортировка численного массива слиянием

@param а[] численный массив
@param left левый край сортируемого блока
@param right правый край сортируемого блока
*/
void merge_sort(int a[], int left, int right)
{
	int middle = (left+right)/2; ///определил элемент, который будет крайним в первой части

	int size_answer = right-left+1;; ///размер ответа равен сумме разбитых массивов
	
	int i = left-left, j = middle+1-left, k = left;
	
	if (size_answer > 2)
	{
		merge_sort(a,left,middle);
		merge_sort(a,middle+1,right);
		
		int *temp = new int[size_answer];
		for (int t = 0, y = left; t < size_answer; t++, y++)
		{
			temp[t] = a[y];
		}
		for (; (i <= middle-left)&&(j <= (right-left)); k++)
		{
			if (temp[i]<=temp[j])
			{
				a[k] = temp[i];
				i++;
			}
			else
			{
				a[k] = temp[j];
				j++;
			}
		}


		if (i == middle+1)
		{
			for (;(j <= right-left); j++, k++)
				a[k] = temp[j];
			

		}
		else
		{
			for (; (i <= middle-left); i++, k++)
				a[k] = temp[i];
		}

		delete temp;

	}
	else
	{
		if (size_answer == 2)
		{
			if(a[left] > a[right])
				swap(&a[left],&a[right]);
		}
	}
}
/**
@function printArray
Функция для печати массива целых чисел

@param *a массив чисел
@param size размер массива
@param lenght длина строки, измеряемая в количестве выеденных элементов
*/
void printArray(int *a, int size, int lenght)
{
	lenght++;
	for (int i = 0; i < size; i++)
	{
		cout << a[i];
		
		if ((a[i]>=0)&&(a[i]<1000))
		{
			cout <<' ';
		}
		if ((a[i]>=0)&&(a[i]<100))
		{
			cout <<' ';
		}
		if ((a[i]>=0)&&(a[i]<10))
		{
			cout <<' ';
		}
		

		if (!((i+1) % lenght))
			cout << "\n";
	}
	cout << "\n\n";

}

void main()
{
	int *a = new int[arraySize];

	srand(time(NULL));

	for (int i = 0; i < arraySize; i++)
	{
		a[i] = rand() % 1000;
	}

	printArray(a, arraySize, lineLenght);

	merge_sort(a, 0, arraySize-1);

	printArray(a, arraySize, lineLenght);


	delete a;


}

