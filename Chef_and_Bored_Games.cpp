#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int t;
    cin >> t;

    while ( t-- ) {

        int n;
        cin >> n;
        long long int ans=0;
        for( auto i = 1 ; i <= n ; i+=2 ) ans += (n-i+1) * (n-i+1) ;
        cout << ans << endl ;
    }

}