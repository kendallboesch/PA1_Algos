#include <vector>
#include <cmath>
#include "shellsort.cpp"

using namespace std;



int main() {
    cout << " Code" << '\t' << "trial#" << '\t' << "n" << '\t' << "num comp" << endl;

    int sort, trial, n, total_trials;

    vector<C1> k;

    vector<int> num;
    num.push_back(500);
    num.push_back(1000);
    num.push_back(1500);
//    num.push_back(2000);
//    num.push_back(2500);
//    num.push_back(3000);
//    num.push_back(3500);
//    num.push_back(4000);
//    num.push_back(4500);
//    num.push_back(5000);
    total_trials = 1000;


    for ( sort = 0; sort < 1; sort++) {       // Sort loop

            for(int y = 0; y < 1; y++) {
                for (trial = 0; trial < total_trials; trial++) {  // trial num loop

                    for (n = 0;n < num[y]; n++) {     // num
                        int a, b, c;
                        a = rand() % 100;
                        b = rand() % 100;
                        c = rand() % 100;

                        C1 x(a, b, c);
                        k.push_back(x);
                        x.compareCount = 0;
                    }
                    //cout << endl << C1::compareCount << '\t';

                    C1::compareCount = 0;
                    //cout << C1::compareCount << '\t' << endl ;
                    shellSort(k, 0);
                    cout << sort << '\t' << '\t' << trial << '\t' << '\t' << num[y] << '\t' << '\t' << C1::compareCount << endl;

                }

            }

        cout << "------------------------------------------" << endl;

    }



    return 0;
}
