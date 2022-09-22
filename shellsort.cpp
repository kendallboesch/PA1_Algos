#include "c1-2.h"
#include <vector>
#include <cmath>

using namespace std;
double fact(double );
double  comb(double );
void shellSort(vector<C1>&, int);

void shellSort(vector<C1>& varray, int code) {
    C1::compareCount = 0;
    vector<int> hlist;
    //  int n = varray.size();
    unsigned int base, k, prevK, result;
    int n = varray.size();
    if (code == 0) {
        hlist.push_back(1);
    } else if (code == 1) {
        //  cout << "CODE: 01" << endl;
        base = 2;
        k = 0;

        bool calculatingKVal = true;

        while (calculatingKVal) {
            prevK = k;
            k++;

            result = pow(base, k);
            //   cout << "K: " << k << endl << "result: " << result << endl;
            if (result >= n) {
                k = prevK;
//                cout << "Final K Val: " << k << endl;
//                cout << "Final Result Val : " << pow(base, k) << endl;
                calculatingKVal = false;
            }

        }

        //POPULATE HLIST
        unsigned int term = pow(base, k);

        int kInc = 0;
        while (term > 1) {
            //cout << "TERM = 2 ^ (" << k << '-' << kInc << ')' << endl;
            term = pow(base, k - kInc);
            //cout << term << endl;
            hlist.push_back(term);
            kInc++;
        }
    } else if (code == 2) {
        // cout << "CODE: 02" << endl;
        base = 2;
        k = prevK = 0;

        bool calculatingKVal = true;

        while (calculatingKVal) {
            prevK = k;
            k++;

            result = pow(base, k) - 1;
            //cout << "K: " << k << endl << "result: " << result << endl;
            if (result >= n) {
                k = prevK;
//                cout << "Final K Val: " << k << endl;
//                cout << "Final Result Val : " << pow(base, k) - 1 << endl;
                calculatingKVal = false;
            }
        }

        //POPULATE HLIST
        unsigned int term = pow(base, k) - 1;

        //hlist.push_back(term);
        unsigned int kInc = 0;
        while (term > 1) {
            // cout << "TERM = 2 ^ (" << k << '-' << kInc << ')' << "-1" << endl;
            term = pow(base, k - kInc) - 1;
            //cout << term << endl;
            hlist.push_back(term);
            kInc++;
        }
    } else if (code == 3) {
        k = 2;
        //cout << "CODE: 03" << endl;
        result = 0;
        bool calculatingKVal = true;
        while (calculatingKVal) {
            prevK = k;
            k++;
            result = comb(k);
           // cout << "K: " << k << endl << "Result: " << result << endl;
            if (result >= n) {
                k = prevK;
                //cout << "Final K: " << k << endl;
                result = comb(k);
                //cout << "Final result val: " << result << endl;
                calculatingKVal = false;
            }
        }
        // POPULATE HLIST

        // int term = comb(k);
        unsigned int term = result;
        // hlist.push_back(term);
        int kDec = 0;
        while (term >= 1) {
            term = comb(k - kDec);
            hlist.push_back(term);
            kDec++;
        }

    }

    int h;

    int count, count2 = 0;
    //C1::compareCount = 0;
    C1 key;
    //key.compareCount=0;

    for (int l = 0; l < hlist.size(); l++) {
        h = hlist[l];
        for (int j = 1; j < n; j++) {
            key==(varray[j]);
            int i = j - h;
            //count2 = C1::compareCount;
            while (i >= 0 && key < varray[i]) {

               // C1::compareCount++;
               // count = C1::compareCount;
               varray[i + h] == varray[i];
                i = i - h;
            }
            varray[i + h] == key;
        }
    }

    // cout << "COUNT: " << count << endl;
    //C1::compareCount = count;

}
double  fact(double n)
{
    if(n <= 1)
    {
        return 1;
    }
    else
    {
        return(n * fact(n-1));
    }
}
 double comb(double k)
{

    return fact(k) / (fact(2) * fact(k - 2));
}

// n is k
// r = 2