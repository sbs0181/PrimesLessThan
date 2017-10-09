// PrimesLessThan.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

vector<bool> VectorOfTrues(int len) {
	vector<bool> vec;
	for (int i = 0; i < len; i++) {
		vec.push_back(true);
	}
	return vec;
}

vector<int> BoolVecToIntVec(vector<bool> boolvec,int shift) {
	vector<int> intvec;
	for (int i = 0; i < boolvec.size(); i++) {
		if (boolvec[i]) {
			intvec.push_back(i + shift);
		}
	}
	return intvec;
}

vector<int> VectorOfPrimeLessThan(int n) {
	vector<bool> IsPrime = VectorOfTrues(n - 1);
	int CurrentInt = 2;
	int CurrentLoc;
	while (CurrentInt <= n) {
		CurrentLoc = CurrentInt - 2;
		if (IsPrime[CurrentLoc]) {
			for (int i = (CurrentLoc + CurrentInt); i < (n - 1); i += CurrentInt) {
				IsPrime[i] = false;
			}
		}
		CurrentInt++;
	}
	return BoolVecToIntVec(IsPrime, 2);
}

template <class T>
void PrintVector(vector<T> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << ", ";
	}
}



int main()
{
	PrintVector<int>(VectorOfPrimeLessThan(10000));
	system("pause");
    return 0;
}

