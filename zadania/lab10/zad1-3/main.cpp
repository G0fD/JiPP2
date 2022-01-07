#include <iostream>
using namespace std;

template <typename T>
T myMax(T a, T b){
    return (a > b)? a: b;
}
template <typename T>
T myMin(T a, T b){
    return (a < b)? a: b;
}
template <typename T>
void printArray(T a[], int size){
    for(int i=0; i<size; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
template <typename T>
void printMatrix(T **a, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

template<typename type1, typename type2>
class Array {
private:
    type2 n;
    type1 *tablica = new type2[n];
public:
    Array(type2 n): n(n) {
        cout<<"stworzono tablice o rozmiarze "<<n<<endl;
    }
};

int main()
{
    int a[5]={1,4,2,1,0};
    double b[6]={1.2,5.1,2,5,3,0.9};
    int w=3, k=2;
    int **tabi = new int *[w];
    double **tabd = new double *[w];
    for(int i=0;i<w;i++) {
        tabi[i] = new int[k];
        tabd[i] = new double[k];
    }
    cout<<"MAX\n";
    cout << myMax<int>(1, 6) << endl;  // max z int
    cout << myMax<double>(8.1, 3.0) << endl; // max z double
    cout << myMax<char>('d', 'f') << endl;   // max z char
    cout<<"\nMIN\n";
    cout << myMin<int>(1, 6) << endl;  // min z int
    cout << myMin<double>(8.1, 3.2) << endl; // min z double
    cout << myMin<char>('d', 'f') << endl;   // min z char
    cout<<"\nPRINT ARRAY\n";
    printArray<int>(a,5); // print int
    printArray<double>(b, 6); // print double
    cout<<"\nPRINT MATRIX\n";
    for(int i = 0; i<w; i++){
        cout << "Podaj element A" << i + 1 << 1 << " : "<<endl;
        for (int j = 0;j < k; ++j){
            cin >> tabi[i][j];
        }
    }
    for(int i = 0; i<w; i++){
        cout << "Podaj element B" << i + 1 << 1 << " : "<<endl;
        for (int j = 0;j < k; ++j){
            cin >> tabd[i][j];
        }
    }
    printMatrix<int>(tabi, w, k);
    cout<<endl;
    printMatrix<double>(tabd, w, k);
    cout<<endl;
    Array<int,int>t{5};
    return 0;
}