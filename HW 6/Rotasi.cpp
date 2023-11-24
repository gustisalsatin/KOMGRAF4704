#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void rotasi(int &x, int &y, double theta) 
{
    double x_double = x;
    double y_double = y;

    x = static_cast<int>(x_double * cos(theta) - y_double * sin(theta));
    y = static_cast<int>(x_double * sin(theta) + y_double * cos(theta));
}

int main() 
{

    int x = 3, y = 8;

    // Sudut rotasi dalam radian ( rotasi sebesar 45 derajat)
    double theta = M_PI / 4.0;

    cout << "Koordinat awal: P(" << x << ", " << y << ")\n";

    // Melakukan rotasi
    rotasi(x, y, theta);

    // Menampilkan matriks
    cout << "Koordinat setelah rotasi: P(" << x << ", " << y << ")\n";
    cout << "Matriks rotasi:\n";
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            if (i == j) 
            {
                cout << fixed << setw(12) << setprecision(6) << ((i == 2) ? 1.0 : cos(theta));
            } 
            else if (j == 2) 
            {
                cout << fixed << setw(12) << setprecision(6) << ((i == 0) ? -sin(theta) : ((i == 1) ? sin(theta) : 0.0));
            } 
            else 
            {
                cout << fixed << setw(12) << setprecision(6) << 0.0;
            }
        }
        cout << "\n";
    }

    return 0;
}