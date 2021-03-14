#include <iostream>

template <typename T>
void printArray(T* array, int size)
{
    for (int i = 0; i < size; ++i)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}


template <typename T>
void QuickSort(T* arr, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[(i + j) / 2]; //средний элемент
    int temp;

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) //меняем местами i-ый и j-ый элементы
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    //массив отсортирован так, что сначала идут arr[i] < pivot, а затем arr[i] > pivot
    if (j > low) //если в подмассиве >1 элемента, то вызываем рекурсивно алгоритм для него
        QuickSort(arr, low, j);
    if (i < high)
        QuickSort(arr, i, high);
}

template <typename T>
T* QuickSortStart(T* massive, int size)
{
    T* arr = new T[size];
    for (int i = 0; i < size; i++) //копия массива massive
        arr[i] = massive[i];

    QuickSort(arr, 0, size - 1); //arr отсортирован по возрастанию
   
    T temp;
    for (int  i = 0; i < size/2; i++) //реверс массива
    {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    return arr;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int size;
    std::cout << "Введите кол-во элементов массива A: ";
    std::cin >> size;
    int* A = new int[size];
    std::cout << "Введите элементы массива A: ";
    for (int i = 0; i < size; i++)
    {
        std::cin >> A[i];
    }
    int* B = QuickSortStart<int>(A, size);
    std::cout << "Массив A: ";
    printArray(A, size);
    std::cout << "Массив B: ";
    printArray(B, size);
    delete[] A;
    delete[] B;
    return (0);
}
