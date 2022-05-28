#include <iostream>
#include "surfaceVector.h"
using namespace std;

int main()
{
    surfaceVector vec1(5, 3);       //Constructor with two separate coordinates 
    surfaceVector vec2({ 3, 5 });   //Constructor with coordinates arr
    surfaceVector vec3;             //Default constructor
    
    vec1 = vec1 * 2;
    vec3 = vec1 - vec2;

    cout << "Vector 3: " << vec3 << "\nLength: " << vec3.getLen() << endl;
    
}