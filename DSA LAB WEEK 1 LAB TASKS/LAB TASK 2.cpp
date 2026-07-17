//             NAME: MUHAMMAD FURQAN ROLL NO: SU92-BSCSM-F24-020
//             LAB TASK 2
    //PASS BY REFERENCE
    #include <iostream>
using namespace std;
void changeValue(int &x)
 {
    x = x + 100; 
    cout << "Inside function (x): " << x << endl;
}
int main() {
    int a = 5;
    cout << "Before function call (a): " << a << endl;
    changeValue(a);
    cout << "After function call (a): " << a << endl;
    return 0;
}
