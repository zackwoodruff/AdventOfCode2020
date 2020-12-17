#include <iostream>
#include <fstream>
#include <vector>

using std::cout; 
using std::endl;


int check_tree_collisions (std::vector<std::vector<bool>> &treeMatrix, int slopeX, int slopeY){
	int nTreeCollisions = 0; 
	int x = 0; // position down the mountain
	int y = 0; // position to the right on the mountain
	int n_columns = treeMatrix[0].size();

	for (size_t i = 0; i<treeMatrix.size(); ++i){
		if (x >= (int)treeMatrix.size()){
			break;
		}

		if (treeMatrix[x][y % (n_columns)]){
			++nTreeCollisions;
		}
		
		x += slopeX; 
		y += slopeY;
	}
	return nTreeCollisions;
}


int main(){
	cout << "Day 3!" << endl;
	
	// Read/parse input
	std::ifstream infile;
    infile.open("day3/input3.txt");
	std::string input;
	
	std::vector<std::vector<bool>> treeMatrix; 
	
	while(std::getline(infile,input)){
		std::vector<bool> treeMatrixRow; 
		for (size_t i = 0; i < input.size(); ++i){
			if (input[i] == '.'){
				treeMatrixRow.push_back(0);
			} else if (input[i] == '#'){
				treeMatrixRow.push_back(1);
			}
		}
		treeMatrix.push_back(treeMatrixRow);
	}
	
	// Print matrix representation of tree locations
	/*for (int cell : treeMatrix[y]){
		cout << cell; 
	} */
	
		
	// Part 1
	// Check the number of collisions for slope dx = 1 (down mountain), dy = 3 (accross mountain)
	cout << check_tree_collisions(treeMatrix,1,3) << endl;
	
	
	// Part 2
	// Check the number of collisions for different slopes and return the product of the nTreeCollisions;
	int slopesX[5] = {1,1,1,1,2};
	int slopesY[5] = {1,3,5,7,1};
	
	long long output = 1; 
	for (int i = 0; i<5; ++i){	
		output *=check_tree_collisions(treeMatrix,slopesX[i],slopesY[i]); 
	}
	cout << output << endl; 
	return 0;
}