//             NAME: MUHAMMAD FURQAN ROLL NO: SU92-BSCSM-F24-020
//             LAB TASK 4
 //TRANSPOSE OF 3*3 MATRIX
 #include <iostream>
using namespace std;
int main()
 {
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int transpose[3][3];
    for(int i=0; i<3; i++)
	 {
        for(int j=0; j<3; j++)
		 {
            transpose[j][i] = arr[i][j];
        }
    }

    cout << "Transpose OF matrix:" << endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++)
		 {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
    int sum = 0;
    for(int j=0; j<3; j++)
	 {
        sum += transpose[0][j];
    }
    cout << "Sum of first row in transpose = " << sum << endl;
    return 0;
}

