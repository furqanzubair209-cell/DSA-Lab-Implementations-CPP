
//             NAME: MUHAMMAD FURQAN ROLL NO: SU92-BSCSM-F24-020
//             LAB TASK 2
//          Merge Two Dynamicaly Created 1D Array with Pointers
#include <iostream>
using namespace std;
int main()
 {
    int n1, n2;
    cout << "Enter size of first array: ";
    cin >> n1;
    cout << "Enter size of second array: ";
    cin >> n2;
    int* a = new int[n1];
    int* b = new int[n2];
    cout << "Enter " << n1 << " elements:\n";
    for (int i = 0; i < n1; i++)
	 {
        cin >> a[i];
    }
    cout << "Enter " << n2 << " elements:\n";
    for (int i = 0; i < n2; i++)
	 {
        cin >> b[i];
    }
    int* c = new int[n1 + n2];
    for (int i = 0; i < n1; i++) 
	{
        c[i] = a[i];
    }
    for (int i = 0; i < n2; i++)
	 {
        c[n1 + i] = b[i];
    }
    cout << "Merged: ";
    for (int i = 0; i < n1 + n2; i++) 
	{
        cout << c[i] << " ";
    }
    cout << endl;
    delete[] a;
    delete[] b;
    delete[] c;
    return 0;
}
