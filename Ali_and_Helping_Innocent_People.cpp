#include <iostream>
#include <string>
using namespace std;

int main() {

    string s,v="AEIOUY";
    cin >> s;
    
    for( auto c : v ) {
        if ( s[2] == c ) {
            cout << "invalid" ;
            return 0 ;
        }
    }

    int x,y ;

    for( auto i = 0 ; i < 8 ; ++i ) {

        if( i==2 or i==6 or i==5 or i==1 ) continue ;
        x = s[i] - '0' ;
        y = s[i+1] - '0' ;
        if( (x+y) % 2 != 0 ) {
            cout << "invalid" ;
            return 0;
        }

    }

    cout << "valid" ;


}