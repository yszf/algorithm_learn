#include <iostream>

class BubbleSort
{
public:
    static void bubble_sort(int arr[], int n)
    {
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < n - 1 - i; ++j)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr, j, j + 1);
                }
            }
        }
    }

    static void swap(int arr[], int x, int y)
    {
        int tmp = arr[x];
        arr[x] = arr[y];
        arr[y] = tmp;
    }

    static void print_array(int arr[], int n)
    {
        for (int i = 0; i < n; ++i)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    int arr[10] = {34, 23, 56, 11, 89, 97, 45, 100, 78, 67};

    std::cout << "before sort:" << std::endl;
    BubbleSort::print_array(arr, 10);

    BubbleSort::bubble_sort(arr, 10);

    std::cout << "after sort:" << std::endl;
    BubbleSort::print_array(arr, 10);

    return 0;
}