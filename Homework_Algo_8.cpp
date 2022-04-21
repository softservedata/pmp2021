#include<iostream>
using namespace std;

const int multiplyer=100000;
void reading_length(int& n, const char* message);
void creating(double*& arr, int n, const char* message);
void simplecreating(int*& arr1, int*& arr2, int n);
double findmax(double* arr, int n);
double findmin(double* arr, int n);
double max_of_two(double arg0, double arg1);
double min_of_two(double arg0, double arg1);
int find_size_of_hash(double* arr1, double* arr2, int n1, int n2);
int make_delta(double arg0, double arg1);
int make_hash_elem(double arg, int delta);
void making_hash_with_elems(int*& hash, double*& arr, int n, int delta);
bool equality(int*& hash1, int*& hash2, int n);


int main()
{
    int n1, n2;
    reading_length(n1, "1");
    double* arr1;
    creating(arr1, n1, "A");
    reading_length(n2, "2");
    double* arr2;
    creating(arr2, n2, "B");
    int delta = make_delta(findmin(arr1, n1), findmin(arr2, n2));
    int n = find_size_of_hash(arr1, arr2, n1, n2);
    int* hash1;
    int* hash2;
    simplecreating(hash1, hash2, n);
    cout << "delta = " << delta << " and length of hash="<<n<<endl;
    making_hash_with_elems(hash1, arr1, n1, delta);
    making_hash_with_elems(hash2, arr2, n2, delta);
    cout<<endl;
    cout << "set of arrays is equal = " << (equality(hash1, hash2, n) ? "true" : "false") << endl;
    return 0;
}

void reading_length(int& n, const char* message){
    do{
        cout<<"n"<<message<<">0 n"<<message<<" int n"<<message<<"=";
        cin>>n;
    }while(n<=0);
}

void creating(double*& arr, int n, const char* message){
    arr=new double[n];
    cout<<"reading array  "<<message<<endl;
    for(int i=0; i<n; i++){
        cout<<message<<"["<<i+1<<"]=";
        cin>>arr[i];
    }
    cout<<endl;
}

void simplecreating(int*& arr1, int*& arr2, int n){
    arr1=new int[n];
    arr2=new int[n];
    for(int j=0; j<n; j++){
        arr1[j]=0;
        arr2[j]=0;
    }
}

double findmax(double* arr, int n){
    double max = arr[0];
    for (int i = 0; i < n; i++){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

double findmin(double* arr, int n){
    double min = arr[0];
    for (int i = 0; i < n; i++){
        if (min > arr[i]){
            min = arr[i];
        }
    }
    return min;
}

double max_of_two(double arg0, double arg1){
    return arg0 > arg1 ? arg0 : arg1;
}

double min_of_two(double arg0, double arg1){
    return arg0 < arg1 ? arg0 : arg1;
}

int find_size_of_hash(double* arr1, double* arr2, int n1, int n2){
    return (((int)((max_of_two(findmax(arr1, n1), findmax(arr2, n2)))*multiplyer))-((int)((min_of_two(findmin(arr1, n1), findmin(arr2, n2)))*multiplyer))) + 1;
}

int make_delta(double arg0, double arg1)
{
    return -((int)((min_of_two(arg0, arg1))*multiplyer));
}

int make_hash_elem(double arg, int delta){
    return ((int)(arg*multiplyer)) + delta;
}

void making_hash_with_elems(int*& hash, double*& arr, int n, int delta){
    for (int i = 0; i<n; i++){
        if(arr[i]==0){
            hash[make_hash_elem(arr[i], delta)]=1;
        }
        else{
            hash[make_hash_elem(arr[i], delta)]=(int)((arr[i])*multiplyer);
        }
    }
}

bool equality(int*& hash1, int*& hash2, int n){
    bool result = true;
    for (int i = 0; result && (i < n); i++){
        if(hash1[i]!=hash2[i]){
            result=false;
        }
    }
    return result;
}

