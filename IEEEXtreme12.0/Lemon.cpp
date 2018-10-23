#include <iostream>
#include <algorithm> 

using namespace std;

int main() {

    int n,m,s;

    cin >> n >> m >> s ;

    int hi = n,lo = 2,curr = 1 ;
    int mid;

    int t = 0 ;
    //cout << endl ;
    while(hi >= lo ) {

        mid = (hi+lo) / 2 ;

        t += ((( mid-curr )*m) + s);

        lo = mid + 1 ;

        curr = mid;        
        
        //cout << hi << " " << lo << endl ;

    }

    cout << t ;

}
