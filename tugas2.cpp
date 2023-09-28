#include <iostream>

using namespace std;

int matriks1[10][10], matriks2[10][10], hasil[10][10];
int i, j, k, m, n, p, q, x, jumlah = 0, pilih;
char ulang = 'y';

void tambah(int m, int n)
{
    cout << "Hasil penjumlahan matriks: \n";
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            hasil[i][j] = matriks1[i][j] + matriks2[i][j];
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }
}

void kurang(int m, int n)
{
    cout << "Hasil pengurangan matriks: \n";
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            hasil[i][j] = matriks1[i][j] - matriks2[i][j];
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }
}

void kali(int m, int n, int p, int q)
{
    if(n != p){
        cout << "Matriks tidak dapat dikalikan satu sama lain.\n";
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

        cout << "Hasil perkalian matriks: \n";
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
    cout << "Hasil perkalian skalar matriks: \n";
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            hasil[i][j] = matriks1[i][j] * x;
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << "KALKULATOR MATRIKS SEDERHANA" << endl;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    
    menu:
    cout << "Pilihlah : " << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "3. Perkalian" << endl;
    cout << "4. Perkalian Skalar" << endl;
    cout << "Pilihanmu(1-4) = ";
    cin >> pilih;

    if(pilih <= 4) {
        cout << "Masukan jumlah baris matriks pertama: ";
        cin >> m;
        cout << "Masukan jumlah kolom matriks pertama: ";
        cin >> n;

        if(pilih == 4) {
            cout <<"Masukan bilangan pengali : ";
            cin >> x;

            cout << "Masukan elemen matriks pertama: \n";
            for(i = 0; i < m; i++){
                for(j = 0; j < n; j++){
                    cin >> matriks1[i][j];
                }   
            }
            goto masuk;
        }

        cout << "Masukan jumlah baris matriks kedua: ";
        cin >> p;
        cout << "Masukan jumlah kolom matriks kedua: ";
        cin >> q;
        
        
        cout << "Masukan elemen matriks pertama: \n";
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                cin >> matriks1[i][j];
            }
        }

        cout << "Masukan elemen matriks kedua: \n";
        for(i = 0; i < p; i++){
            for(j = 0; j < q; j++){
                cin >> matriks2[i][j];
            }
        }

        masuk:
        switch (pilih)
        {
            case 1 : tambah(m, n);
                break;

            case 2 : kurang(m, n);
                break;

            case 3 : kali(m, n, p, q);
                break;
            case 4 : skalar(m, n, x);
                break;
        }

        cout << "Ulangi lagi ? (y/n) : ";
        cin >> ulang;
        if(ulang == 'y') {
            goto menu;
        } 
        else {
            cout << "Terima Kasih Yaa";
        }
    }
    else {
        cout << "Pilihanmu tidak ditemukan " << endl;
        goto menu;
    }
}