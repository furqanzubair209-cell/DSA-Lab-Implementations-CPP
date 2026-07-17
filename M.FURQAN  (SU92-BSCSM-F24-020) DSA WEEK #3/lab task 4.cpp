//             NAME: MUHAMMAD FURQAN 
//         ROLL NO: SU92-BSCSM-F24-020
//             LAB TASK 4	
//          BUBBLE SORT (DESCENDING ORDER)
#include <iostream>
using namespace std;
void bubbleSortdescending(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
	{
        for (int j = 0; j < n - i - 1; j++)
		 {
            if (arr[j] < arr[j + 1]) 
			{
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
 {
    int arr[] = {5, 4, 2, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSortdescending(arr, n);
    for (int i = 0; i < n; i++) 
	{
        cout << arr[i] << " "; 
    }
    return 0;
	}

