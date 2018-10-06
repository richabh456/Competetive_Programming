#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int group( int mid , int* arr , int n , int k ) {

    int dist[] = {0,0,0,0} ;
    int students = 1, pages = 0;

    for ( int i = 0 ; i < n ; ++i ) {
        if ( students > k || mid < arr[i] ) return -1 ;
        pages += arr[i] ;
        if ( i == n-1 && pages < mid ) return -1;
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
        //cout << "\nhi = " << hi << " lo = " << lo << " mid = " << mid ;
        int x = group( mid , arr , n , k ) ;
        //cout << "\nx=" << x ;
        if ( x == -1 ) ++lo ; 
        else if ( x > ans ) {
            lo = mid + 1 ;
            //ans = x ;
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

    cout << endl << ans << endl;

}