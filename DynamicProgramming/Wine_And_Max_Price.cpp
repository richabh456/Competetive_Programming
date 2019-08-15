#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

int max_price( vector<int>& arr, int lo, int hi, int year, vector< vector< int > >& dp ) {

    if ( hi <= lo ) return 0 ;
    if ( dp[lo][hi] != -1 ) return dp[lo][hi] ;
    return dp[lo][hi] = max( ( year * arr[lo] ) + max_price( arr, lo+1, hi, year + 1, dp ), ( year * arr[hi-1] ) + max_price( arr, lo, hi-1, year + 1, dp ) ) ;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    cout.tie(NULL);

    int n ;
    cin >> n ;
    vector< int > arr(n), v(n+1,-1) ;
    vector< vector< int > > dp ;
    for ( auto i = 0 ; i < n ; ++i ) {
        cin >> arr[i] ;
        dp.push_back(v) ;
    }
    dp.push_back(v) ;

    max_price( arr, 0, n, 1, dp ) ;

    cout << dp[0][n] ;


}