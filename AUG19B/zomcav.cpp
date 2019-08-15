#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <list>

using namespace std ;

int main() {

    int t ;
    cin >> t ;

    while ( t-- ) {

        int n ;
        int hxor = 1, vxor = 1 ;
        cin >> n ;

        vector< long long unsigned int > c(n), h(n), v(n,0)  ;

        for ( auto i = 0 ; i < n ; ++i )
            cin >> c[i] ;
        for ( auto i = 0 ; i < n ; ++i ) {
            cin >> h[i] ;
            hxor ^= h[i] ;
        }


        for ( auto i = 0 ; i < n ; ++i ) {

            int l = i - c[i] ;
            if ( l < 0 ) l = 0 ;
            v[l]++ ;

            int r = i + c[i] ;
            if ( r < n-1 )
                v[r+1]-- ;

        }

        vxor ^= v[0] ;
        for ( auto i = 1 ; i < n ; ++i ) {
            v[i] += v[i-1] ;
            vxor^=v[i] ;
        }

        //for ( auto i : v ) cout << i << ' ' ;


        if ( vxor == hxor )
            cout << "YES\n" ;
        else
            cout << "NO\n" ;

    }
}