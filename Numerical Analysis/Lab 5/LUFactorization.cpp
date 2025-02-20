#include <bits/stdc++.h>

using namespace std;

// Function to print a matrix
void printMatrix(vector<vector<double>>&matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            cout << setw(10) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// LU Decomposition function (as defined before)
void LUDecomposition(vector<vector<double>>&A, vector<vector<double>>&L, vector<vector<double>>&U) {
    for (int i = 0; i < A.size(); i++) {
        for (int k = i; k < A.size(); k++) {
            double sum = 0;
            for (int j = 0; j < i; j++)
                sum += (L[i][j] * U[j][k]);
            U[i][k] = A[i][k] - sum;
        }

        for (int k = i; k < A.size(); k++) {
            if (i == k)
                L[i][i] = 1;
            else {
                double sum = 0;
                for (int j = 0; j < i; j++)
                    sum += (L[k][j] * U[j][i]);
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
}

// Function for forward substitution to solve Ly = b
void forwardSubstitution(vector<vector<double>>&L, vector<double>&b, vector<double>&y) {
    for (int i = 0; i < L.size(); i++) {
        y[i] = b[i];
        for (int j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j];
        }
        y[i] /= L[i][i];
    }
}

// Function for backward substitution to solve Ux = y
void backwardSubstitution(vector<vector<double>>&U, vector<double>&y, vector<double>&x) {
    for (int i = U.size() - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < U.size(); j++) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }
}

int main() {
    // Example matrix A (5x5)
    int n;
    cout<<"How many equations do you have?\n";
    cin>>n;

    vector<vector<double>>A(n,vector<double>(n,0));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>A[i][j];
        }
    }

    // Example vector b (Right-hand side of Ax = b)
    vector<double>b(n,0);
    for(int j = 0;j<n;j++){
        cin>>b[j];
    }

    // L and U matrices initialized to zero
    vector<vector<double>>L(n,vector<double>(n,0)) , U(n,vector<double>(n,0));

    // y and x vectors for intermediate and final solutions
    vector<double>y(n,0), x(n,0);

    // Perform LU Decomposition
    LUDecomposition(A, L, U);

    // Step 1: Solve Ly = b using forward substitution
    forwardSubstitution(L, b, y);

    // Step 2: Solve Ux = y using backward substitution
    backwardSubstitution(U, y, x);

    // Output the solution vector x
    cout << "Solution vector x:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}
