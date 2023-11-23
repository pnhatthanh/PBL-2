#include "Graphics.h"
void Graphics::tab(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " ";
    }
}
void Graphics::downLine(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n";
    }
}
string Graphics::tab1(int n){
    string s="";
    for (int i = 0; i < n; i++)
    {
        s+=" ";
    }
    return s;
}
