#include <iostream>
using namespace std;

int main() {
    int array[2][3][4];
    int genap = 2;  
    int ganjil = 1; 

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            array[0][i][j] = genap;
            genap += 2;
            array[1][i][j] = ganjil;
            ganjil += 2;
        }
    }

    cout << "Hasil Penjumlahan Lapis 1 dan 2: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << array[0][i][j] + array[1][i][j];
            if (j < 3) cout << " ";
        }
        cout << endl;
    }

    return 0;
}