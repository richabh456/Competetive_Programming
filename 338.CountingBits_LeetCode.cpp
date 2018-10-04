#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main()
{
    int n,x=1,y=1 ;
    cin >> n ;
    int arr[n+1] ;

    for ( auto i = 0 ; i <= n ; ++i ) {
        cout << "\ni = " << i << "  x = " << x << "  y = " << y  << endl;
        if ( y > pow(2,x) ) {
            cout << "   y == " << pow(2,x)  << endl;
            x++;
            cout << "   x changed to = " << x << " from " << x-1 << " and y = 1 now." << endl;
            y = 1;
        }
        else { y++ ; cout << "   y != " << pow(2,x) << "\n    y changed to = " << y << " from " << y-1  << endl; }
        arr[i] = ((i%2) + ((x-1)%2) + x%2 ) ;
        cout << "arr[" << i << "] = " << arr[i]  << endl;

    }
    cout <<"\n\n\n" ;
    for (auto i = 0 ; i < n+1 ; ++i ) cout << arr[i] << " " ; cout << endl;

    return 0;
}
