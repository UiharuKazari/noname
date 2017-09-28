#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void MAX_SUBSET(vector< vector<int> > &, int);
int NEST(...);

int main() {
	int n;		//how many
	int d;		//dimension
	
	while ( cin >> n >> d ) {
		int num;
		vector< vector<int> > A;
		for (int i = 0; i < n; i++) {
			vector<int> a;
			for ( int j = 0; j < d; j++) {
				cin >> num;
				a.push_back(num);
			}
			sort(a.begin(), a.end());	//every input array
			a.push_back(i+1);			//save position
			A.push_back(a);
		}			

		sort(A.begin(), A,end());

		vector< vector<int> > C;		//save NEST(A[x], A[y]) to C[x][y]
		vector<int> c;					//init C with all -1, NEST true -> 1, false -> 0
		for ( int i = 0; i < n; i++ ) 
			c.push_back(-1);
		for ( int i = 0; i < n; i++ )
			C.push_back(c);

		MAX_SUBSET(A, n);
	}
}

void MAX_SUBSET(vector< vector<int> > &Arr, int len) {
	int i;
	for ( i = 0; i < len-1; i++ ) {
		if ( NEST(Arr[i], Arr[i+1] ) continue;
		else break;	
	}

	if ( i == len-1 ) {		//got
		cout << Arr.size();
		for (vector< vector<int> >::iterator it =  Arr.begin(); it != Arr.end(); it++)
			cout << *(it->end()-1);
		return;
	} else {
		for ( int j = 0; j < len; j++ ) {
			Arr.erase(Arr.begin() + j);
			MAX_SUBSET(Arr, len-1);				//logic error
		}	
	}
}
