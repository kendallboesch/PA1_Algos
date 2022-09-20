#include "c1-2.h"
#include <vector>
#include <cmath>

using namespace std;
int fact(int);
int comb(int);
void shellSort(vector<C1>&, int);

void shellSort(vector<C1>& varray, int code)
{
    vector<int> hlist;
    //  int n = varray.size();
    double base, k, prevK, result;
    int n = varray.size();
    if(code == 0)
    {
        hlist.push_back(1);
    }
    else if (code == 1)
    {
        cout << "CODE: 01" << endl;
        base = 2;
        k  = 0;

        bool calculatingKVal = true;

        while(calculatingKVal)
        {
            prevK = k;
            k++;

            result = pow(base, k);
            cout << "K: " << k << endl << "result: " << result << endl;
            if(result >= n)
            {
                k = prevK;
                cout << "Final K Val: " << k << endl;
                cout << "Final Result Val : " << pow(base, k) << endl;
                calculatingKVal = false;
            }

        }

        //POPULATE HLIST
        double term = pow(base, k);

        double kInc = 0;
        while(term > 1)
        {
            cout << "TERM = 2 ^ (" << k << '-' << kInc << ')' << endl;
            term = pow(base, k - kInc);
            cout << term << endl;
            hlist.push_back(term);
            kInc++;
        }
    }
    else if(code == 2)
    {
        cout << "CODE: 02" << endl;
        base = 2;
        k = prevK = 0;

        bool calculatingKVal = true;

        while(calculatingKVal)
        {
            prevK = k;
            k++;

            result = pow(base, k) - 1;
            cout << "K: " << k << endl << "result: " << result << endl;
            if(result >= n)
            {
                k = prevK;
                cout << "Final K Val: " << k << endl;
                cout << "Final Result Val : " << pow(base, k) - 1 << endl;
                calculatingKVal = false;
            }
        }

        //POPULATE HLIST
        double term = pow(base, k) - 1;

        //hlist.push_back(term);
        double kInc = 0;
        while(term > 1)
        {
            cout << "TERM = 2 ^ (" << k << '-' << kInc << ')' << "-1" << endl;
            term = pow(base, k - kInc) - 1;
            cout << term << endl;
            hlist.push_back(term);
            kInc++;
        }
    }
    else if (code == 3)
    {
        k = 0;
        cout << "CODE: 03" << endl;
        result = 0;
        bool calculatingKVal = true;
        while(calculatingKVal)
        {
            prevK = k;
            k++;
            cout << "K: " << k << endl << "Result: " << result << endl;
            result = comb(k);
            if(result >= n)
            {
                k = prevK;
                cout << "Final K: " << k << endl;
                result = comb(k);
                cout << "Final result val: " << result << endl;
                calculatingKVal = false;
            }
        }
        // POPULATE HLIST

        int term = comb(k);
       // hlist.push_back(term);
        int kDec = 0;
        while( term >= 1)
        {
            term = comb(k - kDec);
            hlist.push_back(term);
            kDec++;
        }

    }
//
    cout << "HLIST: " << endl;
    for(int i = 0; i < hlist.size(); i++)
    {
        cout << hlist[i] << endl;
    }
    int h;

    for(int l = 0; l < hlist.size(); l++)
    {
        h = hlist[l];
        for(int j = 1; j < n; j++)
        {
            C1 key(varray[j]);
            int i = j - h;
            while(i >= 0 && key < varray[i])
            {
                varray[i + h] == varray[i];
                i = i - h;
            }
            varray[i+h] == key;
        }
    }
}
int fact(int n)
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
int comb(int k)
{

    return fact(k) / (fact(2) * fact(k - 2));
}

// n is k
// r = 2