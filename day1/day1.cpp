#include <iostream>
#include <fstream>
#include <vector>
using namespace std; 

int main(){
	cout << "Day 1!" << endl;
	
	// Read input
	int n; 
	vector<int> v; 
	ifstream infile("day1/day1_input2.txt");
	while (infile >> n){
		v.push_back(n);
		//cout << n << endl; 
	}
	
	
	cout << "Part 1: ";
	// Find pair of ints a + b = 2000 (Brute force O(n^2))
	for (auto i = v.begin(); i<v.end()-1; ++i){
		for (auto j = i+1; j<v.end(); ++j){
			if (*i + *j == 2020){
				cout << *i * *j << endl; // Output product a*b
			}
		}
	}

	
	cout << "Part 2: ";
	// Find triplet of ints a + b + c = 2000 (Brute force O(n^3))
	for (auto i= v.begin(); i<v.end()-2; ++i){
		for (auto j= i+1; j<v.end()-1; ++j){
			for (auto k = j+1; k<v.end(); ++k){
				if (*i + *j + *k == 2020){
					cout << *i * *j * *k << endl; // Output product a*b*c
				}
			}
		}
	}
	
	
	return 0; 
}