#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector< vector<int> >::iterator VVIIT;
typedef vector<int>::iterator VIIT;
bool nest(VVIIT a, VVIIT b) {
        for(VIIT it1=a->begin(), it2=b->begin(); it1 != a->end(), it2 != b->end(); it1++, it2++)
                if( *it1 <= *it2) return false;
        return true;
}
int main() {
        string fl;
        int num, dim;
        while (cin >> num >> dim) {
                int n;
                vector< vector<int> > vvect;
                for (int i=0; i<num; i++) {
                        vector<int> vect;
                        for (int j=0; j<dim; j++) {
                                cin >> n;
                                vect.push_back(n);
                        }
                        sort(vect.begin(), vect.end());
                        vvect.push_back(vect);
                }
                int max=num;
                while(max) {
                        /* C(num, max) */
                        int m=num, n=max;
                        vector<int> a;
                        for (int i=0; i<m; i++)
                                a.push_back(i);
                        vector<VIIT> b;
                        for (int i=0; i<n; i++)
                                b.push_back(a.begin()+i);
                        while(1) {
                                /* test ABC nest or not */
                                vector< vector<int> > test;
                                for (int i=0; i<n; i++)
                                        test.push_back(*(vvect.begin() + (**(b.begin()+i))));
                                sort(test.begin(), test.end());
                                bool allnest=true;
                                for (int i=0; i<n-1; i++) {
                                        if(!nest(test.begin()+i+1, test.begin()+i)) {
                                                allnest=false;
                                                break;
                                        }
                                }
#ifdef DEBUG
cout << "DEBUG: ";
for (int i=0; i<n; i++)
        cout << (**(b.begin()+i)) << " ";
cout << "(" << allnest << ")" << endl;
#endif
                                /* if nest */
                                if(allnest) {
                                        cout << max << endl;
                                        for (int i=0; i<n; i++)
                                                cout << find(vvect.begin(), vvect.end(), *(test.begin()+i)) - vvect.begin() + 1 << " ";
                                        cout << endl;
                                        goto lab_out;
                                }
                                /* if not nest */
                                int l=m;
                                for (int i=n-1; i>=0; i--, l--) {
                                        if(*(b.begin()+i) != a.begin()+l-1) {
                                                (*(b.begin()+i))++;
                                                for (int j=i+1; j!=n; j++) {
                                                        *(b.begin()+j)=*(b.begin()+j-1)+1;
                                                }
                                                goto lab_con;
                                        }
                                }
                                break;
                        lab_con:
                                continue;
                        }
                        max--;
                }
        lab_out:
                continue;
        }
        return 0;
}

