#include <iostream>
#include <algorithm>

using namespace std; 

int main() {

    int A,B ;
    bool flag , flag1;
    cin >> A >> B ; 
    int a[A],b[B];
    for ( auto i = 0 ; i < A ; ++i ) cin >> a[i] ;
    for ( auto i = 0 ; i < B ; ++i ) cin >> b[i] ;

    sort(a,a+A) ;
    sort(b,b+B) ;

    int start,end ;
    if ( a[A-1] <= b[0] ) {
        start = a[A-1];
        end = b[0] ;
        flag = 0 ;
    }
    if ( a[0] >= b[B-1] ) {
        start = a[0];
        end = b[B-1] ;
        flag = 1 ;
    }
    int ans = 0;
    for ( auto i = start ; i != end+1 ; ++i ) {
        if (!flag) {
            flag1 = 1 ;
            for ( auto y = 0 ; y < A ; ++y ) {
                if ( i%a[y] != 0 ) {
                    flag1 = 0 ;
                    break ;
                }
            }
            if ( flag1 ) {
                for ( auto y = 0 ; y < B ; ++y ) {
                    if ( b[y]%i != 0 ){
                        flag1 = 0 ;
                        break ;
                    }
                }
            }
            if (!flag1) continue ;
            else ++ans;
        }
        else {
            flag1 = 1 ;
            for ( auto y = 0 ; y < B ; ++y ) {
                if( i%b[y] != 0 ) {
                    flag1 = 0 ;
                    break ;
                }                
            }
            if( flag1 ) {
                for ( auto y = 0 ; y < A ; ++y ) {
                    if ( a[y]%i != 0 ) {
                        flag1 = 0 ;
                        break ;
                    }
                }
            }
            if ( !flag1 ) continue ;
            else ++ans ;
        }
    }

    cout << ans ;

}