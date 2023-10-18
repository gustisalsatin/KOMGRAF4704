#include <iostream>

using namespace std;

int matriks1[10][10], matriks2[10][10], hasil[10][10];
int i, j, k, m, n, p, q, x, jumlah = 0, pilih;
char ulang = 'y';

void addiction (int m, int n)
{
    cout << "Result of matrix addition: \n";
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            hasil[i][j] = matriks1[i][j] + matriks2[i][j];
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }
}

void subtraction (int m, int n)
{
    cout << "Result of matrix subtraction: \n";
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            hasil[i][j] = matriks1[i][j] - matriks2[i][j];
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }
}

void multiplication (int m, int n, int p, int q)
{
    if(n != p){
        cout << "Matrices cant be multiplied by each other.\n";
    }
    else {
        for(i = 0; i < m; i++){
            for(j = 0; j < q; j++){
                for(k = 0; k < p; k++){
                    jumlah = jumlah + matriks1[i][k] * matriks2[k][j];
                }
                hasil[i][j] = jumlah;
                jumlah = 0;
            }
        }

        cout << "Result of matrix multiplication: \n";
        for(i = 0; i < m; i++){
            for(j = 0; j < q; j++){
                cout << hasil[i][j] << "\t";
            }
            cout << endl;
        }
    }
}

void skalar(int m, int n, int x)
{
    cout << "The result of scalar-matrix multiplications: \n";
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            hasil[i][j] = matriks1[i][j] * x;
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << "SIMPLE MATRIX CALCULATOR" << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

    menu:
    cout << "Choose Operations: " << endl;
    cout << "1. Addiction" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Scalar Multiplication" << endl;
    cout << "Your Choice ? (1-4) = ";
    cin >> pilih;

    if(pilih <= 4) {
        cout << "Enter the number of rows of the first matrix: ";
        cin >> m;
        cout << "Enter the number of columns of the first matrix: ";
        cin >> n;

        if(pilih == 4) {
            cout <<"Enter the multiplier number : ";
            cin >> x;

            cout << "Enter the first matrix element: \n";
            for(i = 0; i < m; i++){
                for(j = 0; j < n; j++){
                    cin >> matriks1[i][j];
                }
            }
            goto masuk;
        }

        cout << "Enter the number of rows of the second matrix: ";
        cin >> p;
        cout << "Enter the number of columns of the second matrix: ";
        cin >> q;


        cout << "Enter the first matrix element: \n";
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                cin >> matriks1[i][j];
            }
        }

        cout << "Enter the second matrix element: \n";
        for(i = 0; i < p; i++){
            for(j = 0; j < q; j++){
                cin >> matriks2[i][j];
            }
        }

        masuk:
        switch (pilih)
        {
            case 1 : addiction(m, n);
                break;

            case 2 : subtraction(m, n);
                break;

            case 3 : multiplication(m, n, p, q);
                break;
            case 4 : skalar(m, n, x);
                break;
        }

        cout << "Try again ? (y/n) : ";
        cin >> ulang;
        if(ulang == 'y') {
            goto menu;
        }
    }
    else {
        goto menu;
    }
}
