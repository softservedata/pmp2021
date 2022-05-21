#include <iostream>


using namespace std;
 
int main()
{
    
    int n, m,j,i;
    cout <<"n = "; cin >>n;
    cout <<"m = "; cin >>m;
    
      double **a = new double*[n], max; 
    for (int i = 0; i < n; i++)
       a[i]=new double[m];
      cout<<"Enter the elements of the matrix : \n";
    
    for (int i = 0; i < n; i++)
    
    for (int j = 0; j < m; j++)
    
    cin>>a[i][j]; 
cout<<"Matrix : \n";
for (i=0; i<n; i++)
{

double sum=0.0;
for (j=0; j<m; j++)
cout<<a[i][j]<< " ";
cout<<endl; 
}
cout <<"Swapped matrix: "<<endl;
    for (int i = 1; i < n; i++)    
        for (int k = 0; k < n-i; k++)        
            if (a[k][0]>a[k+1][0])                 
                swap(a[k],a[k+1]);             
            
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; j++)        
        cout << a[i][j] << " ";        
        cout << "\n";
    }    
    
    for (int i = 0; i < n; i++)
    delete [] a[i];
    delete [] a;
    

return 0;
}
