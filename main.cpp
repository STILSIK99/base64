#include <iostream>

#include "tools.h"

using namespace std;

int main(){
    unsigned int a = 1e11;

    cout << sizeof(a) << endl << a << endl; 
    // cout << TOOLS::base64decode(TOOLS::base64encode("Tra\nta\nta")) << endl;
    return 0;
}