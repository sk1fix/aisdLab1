#pragma once
#include<picture.h>
using namespace picture;
int main()
{
    Images<bool> img(10, 10, false);
    img.drawing(9, 7, 2, 2);
    cout << img;
}