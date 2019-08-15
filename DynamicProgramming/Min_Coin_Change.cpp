#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std; 

int minCoinChange( int n, vector<int>& bu_dp, int m , vector<int>& change ) {

    if ( bu_dp[n] != -1 ) return bu_dp[n] ;
    if ( n == 0 ) return 0 ;

    int ans = INT_MAX ;

    for ( auto i = m-1 ; i >=0 ; --i ) {
        if ( n >= change[i] ) {
            int sub_ans = 1 + minCoinChange( n - change[i] , bu_dp , m , change ) ;
            ( sub_ans < ans ) ? ans = sub_ans : ans = ans ; 
        }
    }

    return bu_dp[n] = ans ;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    cout.tie(NULL);

    int n, m ;
    cin >> n >> m ;
    vector< int > td_dp( n+1 , INT_MAX ), bu_dp( n+1 , -1 ), change(m) ;
    for ( auto i = 0 ; i < m ; ++i ) cin >> change[i] ;
    
    minCoinChange( n, bu_dp, m, change ) ;
    
    /*
    tp_dp[0] = 0 ;
    for ( auto i = 0 ; i <= n ; ++i ) {

        for ( auto y = 0 ; y < m ; ++y ) {
            ( change[y] <= i ) ? tp_dp[i] = min( tp_dp[i], 1 + tp_dp[i - change[y]] ) : 1 ;
        }

    }*/
    

    cout << bu_dp[n] << endl ;    

}