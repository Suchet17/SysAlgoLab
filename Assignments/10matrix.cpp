#include <iostream>

using namespace std;

class Matrix{
    private:

    public:
        int** _arr;
        int _rows;
        int _cols;
        Matrix(int rows, int cols){
            _rows=rows;
            _cols=cols;
            _arr = new int* [_rows];
            for (int i=0; i < _rows; i++)
                _arr[i] = new int [_cols];
            for (int i = 0; i<_rows; i++)
                for (int j=0; j<_cols;j++)
                    _arr[i][j]=0;

        }

        ~Matrix(){
            for (int i = 0; i<_rows; i++)
                delete [] _arr[i];
            delete [] _arr;
        }

        void display(){
            for (int i = 0; i<_rows; i++){
                for (int j=0; j<_cols;j++){
                    cout << _arr[i][j] << '\t';
                }
                cout << endl;
            }
            cout << endl;
        }

        Matrix operator+(const Matrix& other) const {
            Matrix res(_rows, _cols);
            for (int i = 0; i<_rows; i++)
                for (int j=0; j<_cols;j++)
                    res._arr[i][j] =  _arr[i][j] + other._arr[i][j];
            return res;
        }

        Matrix operator-(const Matrix& other) const {
            Matrix res(_rows, _cols);
            for (int i = 0; i<_rows; i++)
                for (int j=0; j<_cols;j++)
                    res._arr[i][j] =  _arr[i][j] - other._arr[i][j];
            return res;
        }


        Matrix operator*(const Matrix& other) const {
            if (other._rows != _cols){
                cout << "Size Mismatch Error" << endl;
                return other;
            }
            Matrix res(_rows, other._cols);
            for (int i=0; i<_rows; i++){
                for (int j=0; j<other._cols; j++){
                    for (int k=0; k<_cols; k++){
                        res._arr[i][j] += (_arr[i][j] + other._arr[j][k]);
                    }
                }
            }
            return res;
        }
};

int main(){
    Matrix mat1(2,2);
    mat1._arr[0][0] = 1;
    mat1._arr[0][1] = 2;
    mat1._arr[1][0] = 0;
    mat1._arr[1][1] = 1;
    mat1.display();
    Matrix mat2(2,2);
    mat2._arr[0][0] = 1;
    mat2._arr[0][1] = 2;
    mat2._arr[1][0] = 3;
    mat2._arr[0][1] = 4;
    mat2.display();
    Matrix sum = mat1+mat2;
    sum.display();
    Matrix prod = mat1*mat2;
    prod.display();
    return 0;
}