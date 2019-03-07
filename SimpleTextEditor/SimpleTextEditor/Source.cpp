#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> loadFile(std::string path);
void display(std::vector<std::string>);
void pauseScreen();

int main(int argv, char* argc[]) {
	
	std::vector<std::string> textFile;
	std::string filePath = "test.txt";

	textFile = loadFile(filePath);
	display(textFile);
	pauseScreen();

	return 0;

}

//Load a text file and store its input
std::vector<std::string> loadFile(std::string path) {

	std::vector<std::string> text;
	int row = 0;

	//Open file at path
	std::ifstream fin;
	fin.open(path);

	//Populate vector with input from file
	text.push_back(std::string());
	while (std::getline(fin, text[row])) {
		text.push_back(std::string());
		row++;
	}

	//Close original file
	fin.close();

	return text;
}

void display(std::vector<std::string> text) {

	for (int i = 0; i < text.size(); i++) {
		std::cout << text[i] << std::endl;
	}

}

//Pauses the console window
void pauseScreen() {
	std::cout << "Press ENTER to continue..." << std::endl;
	std::cin.ignore(256, '\n');
	std::cin.get();
}