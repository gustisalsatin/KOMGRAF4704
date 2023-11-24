#include <iostream>
#include <iomanip>
using namespace std;


void translasi(int &x, int &y, int tx, int ty) 
{
    x += tx;
    y += ty;
}

int main() 
{
    // Koordinat Titik P
    int x = 3, y = 8;

    // Vektor Translasi
    int tx = 2, ty = 1;

    // Menampilkan koordinat awal
    cout << "Koordinat awal: P(" << x << ", " << y << ")\n";

    // Translasi
    translasi(x, y, tx, ty);


    // Menampilkan matriks
    cout << "Koordinat sesudah translasi: P(" << x << ", " << y << ")\n";
    cout << "Matriks Translasi:\n";
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            if (i == j) 
            {
                cout << setw(4) << 1;
            } else if (j == 2) 
                {
                    cout << setw(4) << ((i == 0) ? tx : ty);
                } else 
                    {
                        cout << setw(4) << 0;
                    }
        }
        cout << "\n";
    }

    return 0;
}