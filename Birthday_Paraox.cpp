#include <iostream>

using namespace std ;
int main() {

    float p =1 , x;
    cin >> x ;
    float num = 365;
    float denom = 365 ;
    int people = 0 ;
    while ( p > x) {

        p *= (num/denom) ;
        --num ;
        ++people ;

    }

    cout << "Probob is " << p << " and people are " << people << endl ;

}