#include <iostream>
#include <vector>
#include "matrix.h"
#include "ring.h"

using namespace std;

int main() {
    int i,j;  
    cin >> i >> j;
    ring<3> n(i), m(j);
    cout << (n + m).getValue();
    return 0;
}