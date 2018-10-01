#include <iostream>
#define ll long long int
using namespace std;

int main() {

    ll n;
    cin >> n ;

    ll x = n/3 ;

    if ( n%3 == 0) {
        if ( x%3 == 0 ) {

            cout << x-1 << " " << x-1 << ' ' << x+2 ;

        }
        else {

            cout << x << " " << x << ' ' << x ;

        }
    }
    else {

        if( x%3 != 0 ) {

            cout << x << " " << x << ' ' << x+(n - (3*x)) ;

        }
        else{

            cout << x-1 << " " << x+1 << ' ' << x+(n - (3*x)) ;

        }

    }


}
