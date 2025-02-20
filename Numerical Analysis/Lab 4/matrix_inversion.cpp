#include<bits/stdc++.h>
#include<cmath>

using namespace std;

vector<vector<double>>pivot_zero(vector<vector<double>> matrix){
    int size= matrix.size(),col = matrix[0].size();
    int j=size-1;
    set<int>rows;
    for(int i = 0;i<size;i++){
        if(matrix[i][i]==0 && rows.find(i)==rows.end()){
            rows.insert(j);
            for(int k=0;k<col;k++){
                swap(matrix[i][k],matrix[j][k]);
            }
            j--;
        }
    }
    return matrix;
}

// Function to perform Gaussian elimination
vector<vector<double>> gauss_eli(vector<vector<double>>& matrix) {
    int n = matrix.size();
    matrix = pivot_zero(matrix);
    for (int i = 0; i < n; i++) {
        // Make the diagonal contain all 1's
        double diag = matrix[i][i];
        for (int j = 0; j < 2 * n; j++) {
            matrix[i][j] /= diag;
        }
        // Make the elements below the diagonal 0
        for (int k = i + 1; k < n; k++) {
            double factor = matrix[k][i];
            for (int j = 0; j < 2 * n; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
    return matrix;
}

// Function to perform Jordan elimination
vector<vector<double>> jordan_eli(vector<vector<double>>& matrix) {
    int n = matrix.size();
    matrix = pivot_zero(matrix);
    for (int i = n - 1; i >= 0; i--) {
        // Make the elements above the diagonal 0
        for (int k = i - 1; k >= 0; k--) {
            double factor = matrix[k][i];
            for (int j = 0; j < 2 * n; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
    return matrix;
}


void display(const vector<vector<double>>& matrix) {
    int r = matrix.size();
    for (int i = 0; i < r; i++) {
        for (double val : matrix[i]) {
            cout << setw(10) << val << " ";
        }
        cout << endl;
    }
}

void matrix_inversion(vector<vector<double>>& matrix) {
    int n = matrix.size();
    vector<vector<double>> augmented(n, vector<double>(2 * n,0));

    // Initialize augmented matrix with [A | I]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            augmented[i][j] = matrix[i][j];
        }
        augmented[i][i + n] = 1; // Set the identity matrix part
    }

   
    // Apply Gaussian elimination
    augmented = gauss_eli(augmented);
    
    double det = 1;
    for(int i = 0;i<n;i++){
        det*=augmented[i][i];
        if(det==0 || isnan(det)){
            cout<<"Inverse Matrix doesn't exist"<<endl;
            return;
        }
    }

    augmented = jordan_eli(augmented);

    vector<vector<double>> inverse(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse[i][j] = augmented[i][j + n];
        }
    }
    display(inverse);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << "Enter the dimension of the square matrix: ";
    int n;
    cin >> n;
    vector<vector<double>> matrix(n, vector<double>(n));

    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    matrix_inversion(matrix);

    return 0;
}