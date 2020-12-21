#include <iostream>
#include <fstream>
#include <unordered_set>

using std::cout; 
using std::endl;

int main(){
	// Read/parse input
	std::ifstream infile;
	infile.open("day6/input6.txt");
	std::string input;
	
	std::unordered_set<char> questionYesList; 
	int totalYes=0; 
	while(getline(infile,input)){
		//cout << input.c_str() << endl;
		if (input != ""){
			for (char i: input){
				//cout << i;
				questionYesList.insert(i); 
			}
			//cout << endl; 
		}else{ // end of group
			totalYes += questionYesList.size();
			questionYesList.clear(); 
		}	
			//cout << endl;
	}
	totalYes += questionYesList.size(); // Handles last group of fields
	
	cout << "Total y: " << totalYes << endl; 
	return 0; 
}