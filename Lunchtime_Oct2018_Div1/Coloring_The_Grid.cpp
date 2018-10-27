#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    int t;
    cin >> t ;

    while( t-- ) {

        bool flag = 0 ;
        int n,m;
        cin >> n >> m ;
        char x ;
        vector< vector< int > > v(n);
        
        for ( auto i = 0 ; i < n ; ++i ) {
            vector< int > v1(m,0) ;
            for ( auto y = 0 ; y < m ; ++y ) {
                cin >> x ;
                if( x == '#' ) v1[y] = -1 ; 
            }
            v[i] = v1 ;
        }

        for ( auto i = 0 ; i < n-1 ; ++i ) {
            for ( auto y = 0 ; y < m-1 ; ++y ) {

                if( v[i][y] != -1 && v[i+1][y] != -1 && v[i][y+1] != -1 && v[i+1][y+1] != -1 ) {

                    v[i][y] = 1 ;
                    v[i+1][y] = 1 ;
                    v[i][y+1] = 1 ;
                    v[i+1][y+1] = 1 ;

                }
            }
        }

        for ( auto i = 0 ; i < n ; ++i ) {
            for ( auto y = 0 ; y < m ; ++y ) {
                if ( v[i][y] == 0 ) {
                    cout << "NO\n" ;
                    flag = 1 ;
                    break ;
                } 

            }
            if( flag ) break ;
        }

        if ( !flag ) cout << "YES\n" ;

    }

}