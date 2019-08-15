#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    cout.tie(NULL);

    int n ;
    cin >> n ;
    vector< int > v(n) ;
    vector< vector < int > > grid(n), dp(n) ;
    for ( auto i = 0 ; i < n ; ++i ) {
        dp[i] = v ;
        grid[i] = v ;
        for ( auto y = 0 ; y < n ; ++y ){
            grid[i][y] = (i*n)+y+1 ;
            if ( i==y && i==0 ) dp[0][0] = grid[0][0] ;
            else if ( i==0 ) dp[i][y] = grid[i][y] + grid[i][y-1] ;
            else if ( y==0 ) dp[i][y] = grid[i][y] + grid[i-1][y] ;
            else dp[i][y] = min( dp[i-1][y] , dp[i][y-1] ) + grid[i][y] ;
        }
    }
/*
    for ( int i = 0 ; i < n ; ++i ) {
        for ( auto y= 0 ; y < n ; ++y ) {

            if ( i==y && i==0 ) dp[0][0] = grid[0][0] ;
            else if ( i==0 ) dp[i][y] = grid[i][y] + grid[i][y-1] ;
            else if ( y==0 ) dp[i][y] = grid[i][y] + grid[i-1][y] ;
            else dp[i][y] = min( dp[i-1][y] , dp[i][y-1] ) ;

        }
    }
*/
    for ( auto i : dp ) {
        for ( auto y : i ) cout << y << " " ;
        cout << endl ;
    }


}