#include <iostream>

using namespace std;

int main2() {
    int n;
    cout << "Ingrese el tamaño de la matriz: ";
    cin >> n;

    // Declarar la matriz
    float matriz[n][n];

    // Pedir los valores de la matriz al usuario
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Ingrese el valor de la posición [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Calcular el menor elemento de la matriz
    float menor = matriz[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
            }
        }
    }
    cout << "El menor elemento de la matriz es: " << menor << endl;

    // Calcular el promedio de la diagonal principal de la matriz
    float suma = 0;
    for (int i = 0; i < n; i++) {
        suma += matriz[i][i];
    }
    float promedio = suma / n;
    cout << "El promedio de la diagonal principal de la matriz es: " << promedio << endl;

    // Calcular el mayor elemento de la diagonal principal de la matriz
    float mayor = matriz[0][0];
    for (int i = 0; i < n; i++) {
        if (matriz[i][i] > mayor) {
            mayor = matriz[i][i];
        }
    }
    cout << "El mayor elemento de la diagonal principal de la matriz es: " << mayor << endl;

    // Calcular la suma de las dos primeras posiciones de la diagonal principal de la matriz
    float sumaPosiciones = matriz[0][0] + matriz[1][1];
    cout << "La suma de las dos primeras posiciones de la diagonal principal de la matriz es: " << sumaPosiciones << endl;

    return 0;
}