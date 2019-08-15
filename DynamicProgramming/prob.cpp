#include <iostream>
#include <vector> 

using namespace std;

int main() {

    int n, p, k ;
    cin >> n >> p >> k ;
    vector< int > v(n) ;
    for ( auto i = 0 ; i < n ; ++i ) 
        cin >> v[i] ;

    float q = p/2.0 ;
    int s ;
    if ( q > p/2 )
        s = p/2 + 1 ;
    else 
        s = p/2 ;

    vector< int > dp(s+1) ;

    for ( auto i = 0 ; i < n ; ++i ) {

        for ( auto j = 0 ; j <= s ; ++j ) {

            int smp = j ;
            int res = ( smp + v[i]%p ) % p ;
            dp[res] += dp[smp] ; 

        }

        ++dp[v[i]%p] ;

    } 

    cout << dp[k] << endl ;

}