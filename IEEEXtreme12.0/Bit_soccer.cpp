#include <iostream> 
#include <vector> 

using namespace std;

long long int binToDecimal(long long n)
{
    long long int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}

int main() {

    int n;
    long long int x ;
    cin >> n;
    vector< long long int > arr(n) ;
    vector< vector< long long int > > matrix(n) ;
    for ( auto i = 0 ; i < n ; ++i ) cin >> arr[i] ;
    for ( auto i = 0 ; i < n ; ++i ) {
        for( auto y = i+1 ; y < n ; ++ y ) {
            x = binToDecimal(matrix[i] | matrix[b])
            matrix[i][y] = x ;
            matrix[y][i] = x ;
        }

    }



}