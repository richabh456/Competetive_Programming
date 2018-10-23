#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {

    string s;
    bool flag = 1 ;
    cin >> s ;
    vector< char > s1,s2;
    vector< int > vs1(2),vs2(2) ;
    //cout << endl << vs1[0] << " " << vs1[1] ;
    //cout << endl << vs2[0] << " " << vs2[1] ;
    vector< int > arr ;
    
    int i = 0;

    for( auto c : s ) {
 /*       
        cout << "\n\n\ns1 : " ;
        for ( auto x : s1 ) cout << x << " " ;
        
        cout << endl << vs1[0] << " " << vs1[1] ;
        cout << endl << vs2[0] << " " << vs2[1] ;

        cout << "\ns2 : " ;
        for ( auto x : s2 ) cout << x << " " ;
*/
        if ( c == '(' ) {
            if( s1.size() <= s2.size() ) {
                s1.push_back( c );
                arr.push_back( 1 );
                ++vs1[0];
            }
            else {
                s2.push_back( c );
                arr.push_back( 2 );
                ++vs2[0];
            }
        }
        if ( c == '[' ) {
            if( s1.size() <= s2.size() ) {
                s1.push_back( c );
                arr.push_back( 1 );
                ++vs1[1];
            }
            else {
                s2.push_back( c );
                arr.push_back( 2 );
                ++vs2[1];
            }
        }
        if ( c == ')' ) {
            if ( vs1[0] <= vs2[0] && vs1[0] >= 0 ) {
                s2.push_back(c);
                arr.push_back(2);
                --vs2[0] ;
            }
            else if ( vs1[0] > vs2[0] && vs2[0] >= 0 ) {
                s1.push_back(c);
                arr.push_back(1);
                --vs1[0] ;
            }
            else {
                flag = 0 ;
                break ;
            }
        }

        if ( c == ']' ) {
            if ( vs1[1] <= vs2[1] && vs1[1] >= 0 ) {
                s2.push_back(c);
                arr.push_back(2);
                --vs2[1] ;
            }
            else if ( vs1[1] > vs2[1] && vs2[1] >= 0 ) {
                s1.push_back(c);
                arr.push_back(1);
                --vs1[1] ;
            }
            else {
                flag = 0 ;
                break ;
            }
        }

        ++i ;

    }

    if( s1.size() == s2.size() ) {
        if ( flag ) {
            for ( auto c : arr ) {
                cout << c << " " ;
            }
        }
    }
    else cout << "impossible";


}