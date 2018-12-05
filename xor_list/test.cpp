#include <iostream>
#include "./list/XorList.h"

int main(){
    using namespace std;
    XorList<int> xl;

    xl.add(1);
    xl.add(2);
    xl.add(4);
    cout << xl;
    xl.add(4);
    xl.add(5);
    cout << xl;
    cout << xl.contains(1) << endl;
    cout << xl.contains(5) << endl;
    cout << xl.contains(0) << endl;
    xl.remove(0);
    cout << xl;
    xl.remove(1);
    cout << xl;
    xl.remove(5);
    cout << xl;
    xl.remove(3);
    cout << xl;
    cout << xl.findAll(4) << endl;
    cout << xl;
    cout << *(xl.get(0));
}