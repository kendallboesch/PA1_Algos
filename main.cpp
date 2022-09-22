#include <vector>
#include <cmath>
#include "shellsort.cpp"
#include <fstream>

using namespace std;



int main() {
    cout << " Code" << '\t' << "trial#" << '\t' << "n" << '\t' << "num comp" << endl;
    int sort, trial, n, total_trials;
    vector<int> num;
    num.push_back(500);
    num.push_back(1000);
    num.push_back(1500);
    num.push_back(2000);
    num.push_back(2500);
    num.push_back(3000);
    num.push_back(3500);
    num.push_back(4000);
    num.push_back(4500);
    num.push_back(5000);
    total_trials = 24;

    ofstream outFs;
    outFs.open("results.csv");

    for ( sort = 0; sort < 4; sort++) {       // Sort loop

            for(int y = num.size() -1 ; y >= 0; y--) {
                for (trial = 0; trial < total_trials; trial++)
                {  // trial num loop
                    vector<C1> k;

                    for (n = 0;n <= num[y]; n++) {     // num
                        int a, b, c;
                        a = rand() % 100;
                        b = rand() % 100;
                        c = rand() % 100;

                        C1 x(a, b, c);
                        k.push_back(x);
                    }

                    C1::compareCount = 0;
                    shellSort(k, sort);
                    outFs << sort << ',' << trial << ',' << num[y] << ',' << C1::compareCount << endl;
                    cout << sort << ',' << trial << ',' << num[y] << ',' << C1::compareCount << endl;

                }

            }

        //cout << "------------------------------------------" << endl;

    }



    return 0;
}
