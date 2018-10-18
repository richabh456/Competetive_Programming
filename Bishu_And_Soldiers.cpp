#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int main( ) {
    
    int n;
    cin >> n;
    vector< int > arr(n), sum(n) ;
    for ( auto i = 0 ; i < n ; ++i ) cin >> arr[i] ;
    sort(arr.begin(),arr.end()) ;
    sum[0] = arr[0] ;
    for ( auto i = 1 ; i < n ; ++i ) sum[i] = sum[i-1] + arr[i] ;
    int q;
    cin >> q;
    vector< int > quer(q) ;
    for ( auto i = 0 ; i < q ; ++i ) cin >> quer[i] ;
    
    
    for( auto i : quer ) {

        int mid,hi=n-1,lo=0,ans=-1 ;
        while( hi >= lo ) {

            mid = (hi+lo)/2 ;
            if( arr[mid] == i ) { 
                hi = mid-1 ;
                ans = mid ;
            }
            else if ( arr[mid] > i ) hi = mid-1 ;
            else lo = mid+1 ;

        }
        if ( ans == -1 ) {
            if( i > arr[n-1 ] ) cout << n << ' ' << sum[n-1] << '\n' ;
            else cout << 0 << ' ' << 0 << '\n' ;
        }
        else {
            cout << ans+1 << ' ' << sum[ans] << '\n' ;
        }
    }

    return 0;
}
