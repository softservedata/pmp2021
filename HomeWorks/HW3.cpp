#include <iostream>
using namespace std;

int main()
{
int n,sum=1,temp_sum=0,count1=2,count2=2;
cout << "n=";
cin >> n;
for(int i=2;i<=n;i++){
temp_sum+=i;
if(count1>count2){
    sum*=temp_sum;
    temp_sum=0;
    count2=count1;
}
count1++;
}

}