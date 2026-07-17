//             NAME: MUHAMMAD FURQAN ROLL NO: SU92-BSCSM-F24-020
//             LAB TASK 3
//             Find the Most Repeated Value in a Dynamic 1D Array with Pointers

#include <iostream>
using namespace std;
int main()
 {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int mostVal = arr[0], maxCount = 1;
    for (int i = 0; i < n; i++)
	 {
        int count = 0;
        for (int j = 0; j < n; j++)
		 {
            if (arr[j] == arr[i]) 
			{
                count++;
            }
        }
        if (count > maxCount)
		 {
            maxCount = count;
            mostVal = arr[i];
        }
    }
    cout << "Most repeated: " << mostVal  << " (" << maxCount << " times)\n";
    delete[] arr;
    return 0;
}
