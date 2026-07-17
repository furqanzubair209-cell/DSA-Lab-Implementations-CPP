//             NAME: MUHAMMAD FURQAN ROLL NO: SU92-BSCSM-F24-020
//             LAB TASK 5
//       Find Maximum Elements in each Row of a Dynamic 2D array with Pointers
#include <iostream>
using namespace std;
int main() {
    int r, c;
    cout << "Rows and cols: ";
    cin >> r >> c;
    int** a = new int*[r];
    for (int i = 0; i < r; i++)
	 {
        a[i] = new int[c];
    }
    cout << "Enter elements:\n";
    for (int i = 0; i < r; i++) 
	{
        for (int j = 0; j < c; j++) 
		{
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < r; i++) 
	{
        int mx = a[i][0];
        for (int j = 1; j < c; j++) 
		{
            if (a[i][j] > mx)
			 {
                mx = a[i][j];
            }
        }
        cout << "Row " << i + 1 << " max = " << mx << endl;
    }
    for (int i = 0; i < r; i++)
	 {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}
