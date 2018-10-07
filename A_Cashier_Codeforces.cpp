#include <iostream> 
#include <vector>

using namespace std ;

int main() {

    int n, l, a ;
    int x , sum = 0 ;
    cin >> n >> l >> a ;
    vector< int > arr(n) ;
    for ( auto i = 0 ; i < n ; ++i ) {
        cin >> x >> arr[i] ;
        sum += arr[i] ;
    }
    cout << (l - sum ) / a << endl ;
}