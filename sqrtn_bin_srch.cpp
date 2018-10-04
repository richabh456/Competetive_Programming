#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    int hi = n;
    int lo = 1;
    int mid,ans = n;
    while( hi >= lo ) {
        mid = (hi+lo) / 2 ;

        if ( mid*mid <= n ) {
            ans = mid ;
            lo = mid + 1 ;
        }
        else hi = mid - 1 ;
    }

    cout << ans ;

}