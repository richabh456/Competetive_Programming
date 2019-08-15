#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std; 

int minStepsToOne( int n , vector<int>& dp ) {

    if ( dp[n] != -1 ) return dp[n] ; 
    if ( n == 1 ) return 0 ;

    int m = n - 1 ;
    if ( n%2 == 0 ) m = min( m , n/2 ) ;
    if ( n%3 == 0 ) m = min( m , n/3 ) ;

    return dp[n] = 1 + minStepsToOne( m , dp ) ;

}

int main() {

    int n ;
    cin >> n ;
    vector< int > dp( n+1 , -1 ) ;
    cout << minStepsToOne( n , dp ) << endl ;    

}