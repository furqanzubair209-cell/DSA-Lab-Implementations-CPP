//             NAME: MUHAMMAD FURQAN ROLL NO: SU92-BSCSM-F24-020
//             LAB TASK 4
//          Seperate Even and Odd Numbers from a Dynaimic 2D Array Using Pointers
#include <iostream>
using namespace std;
int main()
 {
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
    cout << "Even: ";
    for (int i = 0; i < r; i++)
	 {
        for (int j = 0; j < c; j++)
		 {
            if (a[i][j] % 2 == 0) 
			{
                cout << a[i][j] << " ";
            }
        }
    }
    cout << "\nOdd: ";
    for (int i = 0; i < r; i++)
	 {
        for (int j = 0; j < c; j++)
		 {
            if (a[i][j] % 2 != 0) 
			{
                cout << a[i][j] << " ";
            }
        }
    }
    cout << endl;
    for (int i = 0; i < r; i++)
	 {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}
