#include <vector>
#include <cmath>
#include "shellsort.cpp"

using namespace std;



int main()
{


    vector<C1> k;
    C1 a(9, 22, 0);
    C1 b(7, 0, 0);
    C1 c(17, 0, 0);
    C1 d(2, 0, 0);
    C1 e(9, 27, 0);
    C1 f(27, 0, 0);
    C1 g(0, 3, 2);
    C1 h(0, 0, 8);
    C1 i(0,3,0);

    k.push_back(a);
    k.push_back(b);
    k.push_back(c);
    k.push_back(d);
    k.push_back(e);
    k.push_back(f);
    k.push_back(g);
    k.push_back(h);
    k.push_back(i);

    for(int i = 0; i < k.size(); i++)
    {
        k[i].Print();
    }
    cout << endl;
    shellSort(k,3);
    for(int i = 0; i < k.size(); i++)
    {
        k[i].Print();
    }
    cout << endl;

    return 0;
}
