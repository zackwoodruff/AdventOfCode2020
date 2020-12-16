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
	
	int n_valid_part1 = 0;
	int n_valid_part2 = 0; 
	
	while(std::getline(infile,input)){
		//Example input: 2-6 w: wkwwwfwwpvw
		std::sscanf(input.c_str(),"%d-%d %c: %s",&min, &max, &ch, password);
		
		// Part 1: Check passwords against part 1 rules
		int n_char = 0;
		int i;
		for (i=0; password[i] != '\0'; ++i){
			if (ch==password[i]){
				++n_char; 
			}	
		}
		if (n_char >= min && n_char <= max){
			++n_valid_part1;
		}
		
		// Part 2: Check passwords against part 2 rules
		if((password[min-1]==ch && password[max-1]!=ch) || (password[min-1]!=ch && password[max-1]==ch)){
			++n_valid_part2;
		}
		
	}
	
	// Output number of valid passwords for parts 1 and 2
	cout << "Part 1: " << n_valid_part1 << endl; 
	cout << "Part 2: " << n_valid_part2 << endl; 
	
	return 0;
}