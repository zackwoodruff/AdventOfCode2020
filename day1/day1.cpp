#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using std::cout; 
using std::endl;

int main(){
	cout << "Day 1!" << endl;
	
	// Read input
	int n; 
	std::vector<int> v; 
	std::ifstream infile("day1/day1_input1.txt");
	while (infile >> n){
		v.push_back(n);
	}
	
	
	// Part 1: Find pair of ints a + b = 2000 [O(n)]
	cout << "Part 1: ";
	std::set<int> s; 
	for (int i : v){
		int diff = 2020 - i;
		if (s.count(diff)){
			cout << diff*i << endl;
			break; 
		} else {
			s.insert(i);
		}
	}
	
	
	// Part 2: Find triplet of ints a + b + c = 2000 [O(n)^2]
	cout << "Part 2: ";
	for (size_t i = 0; i < v.size() - 2; ++i){
		std::set<int> s; 		
		for (size_t j = i + 1; j < v.size(); ++j){
			int diff = 2020 - v[i] - v[j];
			if (s.count(diff)){
				cout << diff* v[i] * v[j] << endl;
				break; 
			} else  {
				s.insert(v[j]);
			}
		}
	}
	
	
	return 0; 
}


