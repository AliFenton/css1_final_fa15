// Program comments here 
// You have to make the elf isnt to close to the zombie. But if he make sure hes only next to 3 so he can run away.
// But if he is next to 4 he will be eaten by the zombies.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);
void elfsLocation(ofstream& A_out, string S[][C]);

int main(){
	ifstream fin;
	ofstream fout;

	string array[R][C];

	fin.open("northpole.txt");
	fout.open("status.txt");

	if(fin.fail() || fout.fail()){
		cout << "Error opening file." << endl;
		exit(1);
	}
	
	fout << "Ali Fenton" << endl;

	fillArray(fin, array);
	elfsLocation(fout, array);


	fin.close();
	fout.close();
	return 0;
}

//*****************Fill Array Function*****************
void fillArray(ifstream& A_in, string S[][C]){
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			A_in >> S[i][j];
		}
	}
}

//***************Elfs Location Funciton*****************
void elfsLocation(ofstream& A_out, string S[][C]){
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			//Figuring out were the elf is at
			if((i != 0 && i != 30-1 && j != 0 && j != 50-1)){
				if( (S[i][j] == "@") && (S[i-1][j] == "!" && S[i][j+1] =="!" && S[i+1][j]=="!"&& S[i][j-1]=="!")){
				A_out << "elf" << "[" << i << "]" <<"[" << j << "]" << ":" << "Munch!" << endl; 
				}
				if((S[i][j] == "@") && ((S[i-1][j] == "!" && S[i][j+1] =="!" && S[i+1][j]=="!") || (S[i-1][j] == "!" && S[i+1][j]=="!"&& S[i][j-1]=="!") || (S[i-1][j] == "!" && S[i][j+1] =="!" && S[i][j-1]=="!")||(S[i][j+1] =="!" && S[i+1][j]=="!"&& S[i][j-1]=="!") ))
				{
					A_out << "elf" << "[" << i << "]" <<"[" << j << "]" << ":" << "Run!" << endl;
				}

			}
		}
	}
}



 
