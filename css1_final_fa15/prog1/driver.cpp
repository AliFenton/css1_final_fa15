// Name: Ali Fenton
// Date: 12/17/15
// CSS-1 Fa15 Final Exam Prog 1

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void fillArray(ifstream& A_in, string array[], const int SIZE);

int main(){
	ifstream fin;
	ofstream fout;

	fin.open("passwords.txt");
	fout.open("good_words.txt");

	if(fin.fail() || fout.fail()){
		cout << "Error opening file"<<endl;
		exit(1);
	}

	fout << "Ali Fenton" << endl;

	const int SIZE = 6;
	string possible[SIZE] = {"zymogenic","aboral","Santa","password1","Password!","ambystomidae"};
	
	int count = 0;
	string word;
	while(fin >> word)
	{
		count++;
		
	}

	const int SIZE1 = count;
	string array[SIZE1];

	fillArray (fin, array, SIZE1);
	int count2 = 0;

	//Looks and finds passwords from paswords.txt and see if it has anything in common with array possible. If it does prints it out to good_words.txt
	for(int i = 0; i < SIZE; i++){
		count2 = 0;
		for(int j = 0; j <SIZE1; j++){
			if(possible[i] == array[j]){
				count2++;
			}
		}
		if(count2 == 0){
			fout << possible[i] <<endl;
		}
	}

	fin.close();
	fout.close();
	return 0;
}


//******************Fill Array Function********************
void fillArray(ifstream& fin, string array[], const int SIZE){	
	fin.clear();
	fin.seekg(0);
	string eatWord;
	int i =0;
	array[SIZE];
	while(fin >> eatWord){	
		array[i] = eatWord;
		i++;	
	}
}


 
