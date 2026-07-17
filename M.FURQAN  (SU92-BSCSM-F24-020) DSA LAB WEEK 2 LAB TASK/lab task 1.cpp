
//             NAME: MUHAMMAD FURQAN ROLL NO: SU92-BSCSM-F24-020
//             LAB TASK 1
// Dynamic 1D Array with Pointers that Display Elements Greater Than a Specific Number
#include <iostream>
using namespace std;
int main()
 {
    int n, x;
    cout << "Enter size: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
	 {
        cin >> arr[i];
    }
    cout << "Enter number: ";
    cin >> x;
    cout << "Greater than " << x << ": ";
    for (int i = 0; i < n; i++)
	 {
        if (arr[i] > x)
		 {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
    delete[] arr;
    return 0;
}
