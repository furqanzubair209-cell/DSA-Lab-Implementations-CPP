//             NAME: MUHAMMAD FURQAN ROLL NO: SU92-BSCSM-F24-020
//             LAB TASK 3
#include <iostream>
using namespace std;
int main()
 {
    int arr[3][2] = {{1, 3}, {7, 4}, {10, 8}};
    int searchValue, sum = 0;
    cout << "Enter value to search: ";
    cin >> searchValue;
    bool found = false;
    cout << "Values greater than 5: ";
    for(int i=0; i<3; i++) {
        for(int j=0; j<2; j++) {
            if(arr[i][j] == searchValue)
			 found = true;
            if(arr[i][j] > 5) 
			cout << arr[i][j] << " ";
            sum += arr[i][j];
        }
    }
    cout << endl;
    if(found) cout << "Value found in array!" << endl;
    else cout << "Value not found!" << endl;

    cout << "Sum of all values = " << sum << endl;
    return 0;
}
