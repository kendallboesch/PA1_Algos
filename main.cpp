#include <vector>
#include <cmath>
#include <random>
#include "shellsort.cpp"

using namespace std;



int main() {
    cout << " Code" << '\t' << "trial#" << '\t' << "n" << '\t' << "num comp" << endl;

    int sort, trial, n, comp;
    sort = 0;
    trial = 0;
    n = 500;
    vector<C1> k;
    int s,j,i;

    for (int s = 0; s < 3; s++) {
        for (int j = 0; j < 10; j++) {


            for (int i = 0; i < 100; i++) {
                int a, b, c;
                a = rand() % 100;
                b = rand() % 100;
                c = rand() % 100;

                C1 x(a, b, c);
                k.push_back(x);
            }
            C1::compareCount = 0;
            shellSort(k, 0);
            cout << s << '\t' << '\t' << j << '\t' << '\t' << 100 << '\t' << '\t' << C1::compareCount << endl;
        }

    }





    return 0;
}
