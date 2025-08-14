#include <iostream>
#include <iomanip>
using namespace std;

void generateMagicSquare(int n) {
    if (n % 2 == 0) {
        cout << "Magic square is possible only for odd order in this method.\n";
        return;
    }

    int magic[n][n];
    // Initialize all positions as 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magic[i][j] = 0;

    int i = 0;      // Start row
    int j = n / 2;  // Start column
    for (int num = 1; num <= n * n; ) {
        magic[i][j] = num++;
        int newi = (i - 1 + n) % n;
        int newj = (j + 1) % n;

        if (magic[newi][newj] != 0) { // Cell already filled
            i = (i + 1) % n;
        } else {
            i = newi;
            j = newj;
        }
    }

    // Display the magic square
    cout << "Magic Square of size " << n << ":\n";
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++)
            cout << setw(4) << magic[r][c];
        cout << "\n";
    }

    cout << "\nMagic Constant: " << n * (n * n + 1) / 2 << "\n";

    // Calculate sums
    cout << "\nRow sums:\n";
    for (int r = 0; r < n; r++) {
        int sum = 0;
        for (int c = 0; c < n; c++)
            sum += magic[r][c];
        cout << "Row " << r + 1 << ": " << sum << "\n";
    }

    cout << "\nColumn sums:\n";
    for (int c = 0; c < n; c++) {
        int sum = 0;
        for (int r = 0; r < n; r++)
            sum += magic[r][c];
        cout << "Column " << c + 1 << ": " << sum << "\n";
    }

    // Diagonal sums
    int diag1 = 0, diag2 = 0;
    for (int k = 0; k < n; k++) {
        diag1 += magic[k][k];             // Top-left to bottom-right
        diag2 += magic[k][n - 1 - k];     // Top-right to bottom-left
    }
    cout << "\nDiagonal 1 sum: " << diag1 << "\n";
    cout << "Diagonal 2 sum: " << diag2 << "\n";
}

int main() {
    int n;
    cout << "Enter odd size of magic square: ";
    cin >> n;
    generateMagicSquare(n);
    return 0;
}
