#include <iostream> 
#include <vector>

using namespace std ;

int main() {

    long long int n, l, a ;
    long long int y , sum = 0 ;
    cin >> n >> l >> a ;
    vector< long long int > arr(n) ;
    for ( auto i = 0 ; i < n ; ++i ) {
        cin >> y >> arr[i] ;
        sum += arr[i] ;
    }
    cout << (l - sum ) / a ;
}