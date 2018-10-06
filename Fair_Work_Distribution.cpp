#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int group( int mid , int* arr , int n , int k ) {

    int dist[k] ;
    int students = 1, pages = 0;

    for ( int i = 0 ; i < n ; ++i ) {
        if ( students > k || mid < arr[i] ) return -1 ;
        pages += arr[i] ;
        if ( pages >= mid ) {
            dist[students - 1] = pages ;
            pages = 0 ;
            ++students ;
        }
    }

    return *max_element(dist,dist+k) ;

}

int main() {

    int n,k,sum,min=__INT_MAX__ , ans = __INT_MAX__;
    cin >> n >> k ;
    int arr[n] ;
    for ( auto i = 0 ; i < n ; ++i ) {
        cin >> arr[i] ;
        sum += arr[i] ;
        if( arr[i] < min ) min = arr[i] ;
    }

    int hi = sum , lo = min ;
    int mid,last ; ///last = 1 : hi  ,   last = 0 lo

    while ( hi >= lo ) {

        mid = (hi + lo) / 2 ;

        int x = group( mid , arr , n , k ) ;

        if ( x == -1 ) ++lo ; 
        else if ( x > ans ) {
            lo = mid + 1 ;
        }
        else if ( x < ans ) { 
            hi = mid - 1 ;
            ans = x;
        }
        else {
            if ( last == 1 ) hi = mid - 1 ;
            else lo = mid + 1 ;
        }

    }

    cout << ans << endl;

}