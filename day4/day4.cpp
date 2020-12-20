#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <set>

using std::cout; 
using std::endl;

int main(){
	// Read/parse input
	std::ifstream infile;
	infile.open("day4/input4.txt");//_test
	std::string input;
	
	char field[100]{};
	char value[100]{};
	
	std::string inp2; 
	std::set<std::string> fieldListCurrentPassport;
	std::set<std::string> fieldListToCheck = {"byr","ecl","eyr","hcl","hgt","iyr","pid"};//,"cid"}; (ignore cid)
	
	int nValidPassports = 0; 
	bool is_valid = 0;
	while(std::getline(infile,input)){
		//cout << input.c_str() << endl;
		if (input != ""){
			std::istringstream in;
			in.str(input);
			while(in >> inp2) {
				//cout << inp2 << endl;
				sscanf(inp2.c_str(),"%[^:]:%s",field, value);
				
				auto fieldItr = fieldListToCheck.find(field); 
				if (fieldItr != fieldListToCheck.end()){
					//cout  << field << ":";
					if (*fieldItr == "byr"){ // Check valid birth year
						int val = std::atoi(value);
						if (val >= 1920 && val <= 2002){
							cout << field << ":" << value << " ";
							fieldListCurrentPassport.insert(field);
						}
					} else if (*fieldItr == "ecl"){
						int flag=0; 
						if 		 (strcmp(value, "amb")==0){
							flag=1;
						}else if (strcmp(value, "blu")==0){
							flag=1; 
						}else if (strcmp(value, "brn")==0){
							flag=1; 
						}else if (strcmp(value, "gry")==0){
							flag=1; 
						}else if (strcmp(value, "grn")==0){
							flag=1; 
						}else if (strcmp(value, "hzl")==0){
							flag=1; 
						}else if (strcmp(value, "oth")==0){
							flag=1; 
						}
						
						if (flag){
							cout << field << ":" << value << " ";
							fieldListCurrentPassport.insert(field);
						}
					} else if (*fieldItr == "eyr"){ // Check valid expiration year
						int val = std::atoi(value);
						if (val >= 2020 && val <= 2030){
							cout << field << ":" << value << " ";
							fieldListCurrentPassport.insert(field);
						}
					} else if (*fieldItr == "hcl"){ // Check hair color
						if (value[0]=='#' && strlen(value) == 7){
							int flag = 1; 
							for (int i = 1; i<7; ++i){
								if ( (value[i] >= '0' && value[i] <= '9') || (value[i] >= 'a' && value[i] <= 'f')){
									continue;
								} else{
									flag = 0;
									break;
								}
							}
							
							if (flag){
								cout << field << ":" << value << " ";
								fieldListCurrentPassport.insert(field);
							}
						}
						
					} else if (*fieldItr == "hgt"){ // Check if the height is valid 
						int val;
						char units[3]{}; 
						sscanf(value, "%d%s", &val,units);

						if (strcmp(units, "cm")==0){
							if (val >= 150 && val <= 193){
								cout << field << ":" << value << " ";
								fieldListCurrentPassport.insert(field);
							}
						}else if(strcmp(units, "in")==0){
							if (val >= 59 && val <= 76){
								cout << field << ":" << value << "  ";
								fieldListCurrentPassport.insert(field);
							}
						}
					} else if (*fieldItr == "iyr"){ // Check valid issue year
						int val = std::atoi(value);
						if (val >= 2010 && val <= 2020){
							cout << field << ":" << value << " ";
							fieldListCurrentPassport.insert(field);
						}
					} else if (*fieldItr == "pid"){ // Check passport number
						if (strlen(value) == 9) {
							int flag = 1;
							for (int i = 0; i < 9; ++i) {
								if (value[i] >= '0' && value[i] <= '9'){
									continue;
								} else{
									flag = 0;
									break;
								}
							}
							if (flag){
								cout << field << ":" << value << " ";
								fieldListCurrentPassport.insert(field);
							}							
						}
					}
				}
			}
		}else{
			
			is_valid = 0;
			fieldListCurrentPassport.clear();
			cout << endl; 			
		}
		//cout << endl; 
		if (fieldListCurrentPassport.size() == 7 && !is_valid){
			++nValidPassports;
			is_valid =1; 
			cout << nValidPassports << " ";
		} else {
			/*for (auto elem : fieldListCurrentPassport){
				cout << elem << " ";
			}
			cout << endl; 
			*/
		}
		
		
	}
	
	cout << endl;
	cout << nValidPassports << endl; 
	return 0; 
}