#include <iostream>

using namespace std;

int main()
{
//A    
    int n;
	cout << "Enter n=";
	cin >> n;
	int sum = 0;
	int s1 = 1;
	int q =1;
	int w=1;
	for (int i = 1; i <= n; i++) {
        if (i - q == 0) {
            sum += i;
            s1 *= sum;
            sum = 0;
            w += 1;
            q += w;
        }
        else if (i == n) {
            sum += i;
            s1 *= sum;
        }
        else {
            sum += i;
        }
    }
    cout << "(A) S = " << s1 <<endl;
    
    
//B    
    
   int s2 = 0;
    for (int i = 1; i <= n; ++i) {
       int k = 1;
        for (int j = 1; j <= i; ++j) {
            k *= j;
        }
        s2 += k;
    }
    cout << "(B) S = " << s2 << endl;
    
    
//C 
    int s3 = 1;
    int sum1 = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = i;j <= i * i; j++) {
            s3 *= j;
        }
        sum1 += s3;
        s3 = 1;
    }
    cout << "(C) S = " << sum1 << endl;
            
            
            

    return 0;
	
}
