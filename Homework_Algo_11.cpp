#include <iostream>
using namespace std;
void reading_length(int& n, const char* message);
void creating(int*& arr, int n, const char* message);
void simplecreating0(int*& arr1, int n);
void simplecreating(int*& arr1, int*& arr2, int n);
int findmax(int* arr, int n);
int findmin(int* arr, int n);
int max_of_two(int arg0, int arg1);
int min_of_two(int arg0, int arg1);
int find_size_of_hash(int* arr1, int* arr2, int n1, int n2);
int make_delta(int arg0, int arg1);
int make_hash_elem(int arg, int delta);
void making_hash_with_elems(int*& hash, int*& arr, int n, int delta);
void unionity(int*& hash1, int*& hash2, int n, int& p, int delta, int*& uni);
void intersectionity(int*& hash1, int*& hash2, int n, int& p, int delta, int*& inter);
void print(int*& matr, int n, const char* message);


int main()
{
    int n1, n2;
    reading_length(n1, "1");
    int* arr1;
    creating(arr1, n1, "A");
    reading_length(n2, "2");
    int* arr2;
    creating(arr2, n2, "B");
    int delta = make_delta(findmin(arr1, n1), findmin(arr2, n2));
    int n = find_size_of_hash(arr1, arr2, n1, n2);
    int* hash1;
    int* hash2;
    simplecreating(hash1, hash2, n);
    cout << "delta = " << delta << " and length of hash="<<n<<endl;
    int* uni;
    int* inter;
    simplecreating0(uni, n);
    simplecreating0(inter, n);
    int p1=0;
    int p2=0;
    making_hash_with_elems(hash1, arr1, n1, delta);
    making_hash_with_elems(hash2, arr2, n2, delta);
    unionity(hash1, hash2, n, p1, delta, uni);
    intersectionity(hash1, hash2, n, p2, delta, inter);
    cout<<endl;
    print(uni, p1, "union");
    print(inter, p2, "intersection");
    delete[] arr1;
    delete[] arr2;
    delete[] hash1;
    delete[] hash2;
    delete[] uni;
    delete[] inter;
    return 0;
}

void reading_length(int& n, const char* message){
    do{
        cout<<"n"<<message<<">0 n"<<message<<" int n"<<message<<"=";
        cin>>n;
    }while(n<=0);
}

void creating(int*& arr, int n, const char* message){
    arr=new int[n];
    cout<<"reading array  "<<message<<endl;
    for(int i=0; i<n; i++){
        cout<<message<<"["<<i+1<<"]=";
        cin>>arr[i];
    }
    cout<<endl;
}

void simplecreating0(int*& arr1, int n){
    arr1=new int[n];
}

void simplecreating(int*& arr1, int*& arr2, int n){
    arr1=new int[n];
    arr2=new int[n];
    for(int j=0; j<n; j++){
        arr1[j]=0;
        arr2[j]=0;
    }
}

int findmax(int* arr, int n){
    int max = arr[0];
    for (int i = 0; i < n; i++){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

int findmin(int* arr, int n){
    int min = arr[0];
    for (int i = 0; i < n; i++){
        if (min > arr[i]){
            min = arr[i];
        }
    }
    return min;
}

int max_of_two(int arg0, int arg1){
    return arg0 > arg1 ? arg0 : arg1;
}

int min_of_two(int arg0, int arg1){
    return arg0 < arg1 ? arg0 : arg1;
}

int find_size_of_hash(int* arr1, int* arr2, int n1, int n2){
    return max_of_two(findmax(arr1, n1), findmax(arr2, n2))-min_of_two(findmin(arr1, n1), findmin(arr2, n2)) + 1;
}

int make_delta(int arg0, int arg1)
{
    return -(min_of_two(arg0, arg1));
}

int make_hash_elem(int arg, int delta){
    return arg + delta;
}

void making_hash_with_elems(int*& hash, int*& arr, int n, int delta){
    for (int i = 0; i<n; i++){
        if(arr[i]==0){
            hash[make_hash_elem(arr[i], delta)]=1;
        }
        else{
            hash[make_hash_elem(arr[i], delta)]=arr[i];
        }

    }
}

void unionity(int*& hash1, int*& hash2, int n, int& p, int delta, int*& uni){
    for (int i = 0; i < n; i++){
        if((hash1[i]!=0)||(hash2[i]!=0)){
            p+=1;
            uni[p-1]=i-delta;
        }
    }
}

void intersectionity(int*& hash1, int*& hash2, int n, int& p, int delta, int*& inter){
    for (int i = 0; i < n; i++){
        if((hash1[i]!=0)&&(hash2[i]!=0)){
            p+=1;
            inter[p-1]=i-delta;
        }
    }
}

void print(int*& matr, int n, const char* message){
    cout<<message<<endl;
    for(int i=0; i<n; i++){
        cout<<matr[i]<<"\t";
    }
    cout<<endl;
}

