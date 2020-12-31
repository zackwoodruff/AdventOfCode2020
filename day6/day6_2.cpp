#include <iostream>
#include <fstream>
#include <map>

using std::cout; 
using std::endl;

int main(){
	// Read/parse input
	std::ifstream infile;
	infile.open("day6/input6.txt");
	std::string input;

	std::map<char,int> questionYesMap; 
	int totalYes = 0; // Total yeses in all groups
	int nGroup = 0; // number of people in each customs group
	
	while(getline(infile,input)){
		if (input != ""){ // additional group member
			for (char i: input){
				questionYesMap[i]++;
			}
			nGroup++; 
		}else{ // end of group
			// Check which questions answered yes for all group members
			for (auto it = questionYesMap.begin(); it!= questionYesMap.end(); ++it){
				if (it->second == nGroup){
					totalYes++; 
				}
			} 
	
			questionYesMap.clear(); // reset answers for next group
			nGroup = 0; // initialize group size to 0
		}	
	}
	
	// Handle last group of fields
	for (auto it = questionYesMap.begin(); it!= questionYesMap.end(); ++it){
		if (it->second == nGroup){
			totalYes++; 
		}
	} 
	
	// Output answer
	cout << "Total y: " << totalYes << endl; 
	return 0; 
}