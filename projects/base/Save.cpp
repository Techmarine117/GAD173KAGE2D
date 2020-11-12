#include "Save.h"
using namespace std;

void Save::Saved(std::string fileName, std::string filecontents) 
{
	ofstream myfile;
	myfile.open(fileName + ".txt");
	myfile << filecontents;
	myfile.close();

}

std::string Save::Load(std::string fileName) 
{
	fstream myfile;
	myfile.open(fileName + ".txt");
	std::string data;
	myfile >> data;

	myfile.close();
	return data;
}
