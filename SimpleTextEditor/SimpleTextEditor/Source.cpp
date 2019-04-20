#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> loadFile(std::string path);
void saveFile(std::string name, std::vector<std::string>);
void display(std::vector<std::string>);
void pauseScreen();

int main(int argv, char* argc[]) {
	
	std::vector<std::string> textFile;
	std::string filePath = "test.txt";
	std::string newName = "output.txt";

	textFile = loadFile(filePath);
	display(textFile);
	saveFile(newName, textFile);
	pauseScreen();

	return 0;

}

//Load a text file and store its input
std::vector<std::string> loadFile(std::string path) {

	std::vector<std::string> text;

	//Open file at path
	std::ifstream fin;
	fin.open(path);

	//Populate vector with input from file
	for (int row = 0; !fin.eof(); row++) {
		text.push_back(std::string());
		std::getline(fin, text[row]);
	}
	
	//Close original file
	fin.close();

	return text;
}

//Save a given vector of strings to a new, named file
void saveFile(std::string fileName, std::vector<std::string> text) {

	std::ofstream fout;
	fout.open(fileName);

	//Save each line of text
	for (int i = 0; i < text.size(); i++) {
		fout << text[i];
		if (i < text.size() - 1) fout << std::endl;	//Add a newline to all except the last line of text
	}
	
	fout.close();
}

//Display the current text file
void display(std::vector<std::string> text) {

	//Display each line of text followed by a newline
	for (int i = 0; i < text.size(); i++) {
		std::cout << text[i] << std::endl;
	}

}

//FIXME: find a way to unpause after one button press
//Pause the console window
void pauseScreen() {
	std::cout << "Press ENTER to continue..." << std::endl;
	std::cin.ignore(256, '\n');
	std::cin.get();
}