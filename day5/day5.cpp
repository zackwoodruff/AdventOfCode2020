#include <iostream>
#include <fstream>
#include<unordered_set>

using std::cout; 
using std::endl;

int main(){
	// Read/parse input
	std::ifstream infile;
	infile.open("day5/input5.txt");
	std::string input;
	
	std::unordered_set<int> seatIdList;
	int maxIdVal = 0;
	int minIdVal = 1000; 
	while (std::getline(infile,input)){		
		// Find row number
		int row = 0; 
		int add = 64;
		for (int i=0; i<7; ++i){
			//cout<< input[i];
			if (input[i]=='F'){
				row += 0;
			}else if (input[i]=='B'){
				row += add; 
			}
			add /= 2;   
		}
		//cout << " " << row << " ";
		
		// Find column number
		int column = 0; 
		add = 4; 
		for (int i=0; i<3; ++i){
			//cout<< input[i+7];
			if (input[i+7]=='L'){
				column += 0;
			}else if (input[i+7]=='R'){
				column += add; 
			}
			add /= 2;   
		}
		//cout << " " << column << endl;
		
		// Calculate seat ID and add to list
		int seatId = row*8 + column;
		seatIdList.insert(seatId); 	
		
		// Find max and min seat IDs
		if (seatId > maxIdVal){
			maxIdVal = seatId;
		}
		if (seatId < minIdVal){
			minIdVal = seatId;
		}	
	}
	
	// Output max ID (Part 1)
	cout << "Max ID: " << maxIdVal << endl; 
	
	// Find missing seat ID (Part 2)
	for (int i = minIdVal+1; i < maxIdVal; ++i){
		if (seatIdList.find(i) == seatIdList.end()){
			cout << "My ID: " << i << endl; 
		}
	}
	
	return 0; 
}