#include <iostream>
#include <fstream>
#include <vector>

using std::cout; 
using std::endl;

int main(){
	cout << "Day 2!" << endl;
	
	// Read/Parse Input
	std::ifstream infile;
    infile.open("day2/day2_input.txt");
	std::string input;
	
	int min, max;
	char ch; 
	char password[100];
	
	int n_valid = 0; 
	while(std::getline(infile,input)){
		//Example input: 2-6 w: wkwwwfwwpvw
		std::sscanf(input.c_str(),"%d-%d %c: %s",&min, &max, &ch, password);
		
		// Part 1: Check passwords against rules
		int n_char = 0;
		for (int i=0; password[i] != '\0'; ++i){
			if (ch==password[i]){
				++n_char; 
			}	
		}
		if (n_char >= min && n_char <= max){
			++n_valid;
		}
	}
	cout << n_valid << endl; 
	
	return 0;
}