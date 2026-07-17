//             NAME: MUHAMMAD FURQAN 
//         ROLL NO: SU92-BSCSM-F24-020
//             LAB TASK 2
//            INSERTION SORT (DESCENDING ORDER)    
#include <iostream>
using namespace std;
void insertionSortdescending(int arr[], int n) 
{
    for (int i = 1; i < n; i++)
	 {
        int key = arr[i]; 
        int j = i - 1;  
        while (j >= 0 && arr[j] < key) 
		{
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; 
    }
}

int main()
 {
    int arr[] = {6, 2, 7, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSortdescending(arr, n);
    for (int i = 0; i < n; i++)
	 {
        cout << arr[i] << " "; 
    }
    return 0;
}
