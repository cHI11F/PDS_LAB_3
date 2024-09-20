#include <iostream>
#include <vector>

using namespace std;


unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}


unsigned long long arrangements(int n, int r) {
    return factorial(n) / factorial(n - r);
}


vector<vector<unsigned long long>> stirling_second_kind(int n) {
    vector<vector<unsigned long long>> S(n + 1, vector<unsigned long long>(n + 1, 0));
    
    S[0][0] = 1; 

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            S[i][j] = j * S[i - 1][j] + S[i - 1][j - 1];
        }
    }
    
    return S;
}


vector<unsigned long long> bell_numbers(int n) {
    vector<vector<unsigned long long>> S = stirling_second_kind(n);
    vector<unsigned long long> B(n + 1, 0);
    
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            B[i] += S[i][j];
        }
    }
    
    return B;
}

int main() {
    int n, r;

    
    cout << "Введіть значення n для обчислення розміщень: ";
    cin >> n;
    cout << "Введіть значення r для обчислення розміщень: ";
    cin >> r;

    
    cout << "1. Кількість розміщень без повторень A(" << n << ", " << r << ") = " << arrangements(n, r) << endl;

    
    cout << "\nВведіть значення i для обчислення чисел Стірлінга другого роду і чисел Белла: ";
    int i;
    cin >> i;

    
    vector<vector<unsigned long long>> stirling = stirling_second_kind(i);

    cout << "2. Таблиця чисел Стірлінга другого роду для n = " << i << ":" << endl;
    for (int j = 0; j <= i; ++j) {
        for (int k = 0; k <= j; ++k) {
            cout << stirling[j][k] << "\t";
        }
        cout << endl;
    }

    
    vector<unsigned long long> bell = bell_numbers(i);

    cout << "Числа Белла для n = " << i << ":" << endl;
    for (int j = 0; j <= i; ++j) {
        cout << "B(" << j << ") = " << bell[j] << endl;
    }

    return 0;
}
