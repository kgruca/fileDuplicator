// File Duplicator
// Name: Krzysztof Gruca


#include <iostream>
#include <string>
#include <fstream>

void intro();
std::string inputPath();
std::string outputPath();
void openInput(std::ifstream &, std::string);
void openOutput(std::ofstream &, std::string);
void createClonedFile(std::ifstream &, std::ofstream &, std::string);
void outro(std::string);
bool repeat();
void goodBye();

int main() {

	std::ifstream inputFile;
	std::ofstream outputFile;
	std::string inputLoc, outputLoc, input;
	bool cloneAnother;

	do {
		intro();

		inputLoc = inputPath();

		outputLoc = outputPath();

		openInput(inputFile, inputLoc);

		openOutput(outputFile, outputLoc);

		createClonedFile(inputFile, outputFile, input);

		outro(outputLoc);

		cloneAnother = repeat();
	} while (cloneAnother);

	goodBye();

	system("pause");
	return 0;
}

void intro() {
	std::cout << "Hello! I'm your personal assistant/file duplicator!" << std::endl;
	std::cout << "I will ask you a few questions pertaining to the file you wish to clone." << std::endl << std::endl;
}

std::string inputPath() {
	std::string inputLocation;

	std::cout << "First, please enter the path to the file that will be cloned: ";
	std::cin >> inputLocation;

	return inputLocation;
}

std::string outputPath() {
	std::string outputLocation;

	std::cout << "\nNow, enter the name/path of the cloned file: ";
	std::cin >> outputLocation;

	return outputLocation;
}

void openInput(std::ifstream &inFile, std::string name) {
	inFile.open(name.c_str());

	while (inFile.fail()) {
		std::cout << "\n\nERROR: Cannot open file. Please provide the correct path: ";
		std::cin >> name;
		inFile.open(name.c_str());
	}
}

void openOutput(std::ofstream &outFile, std::string name) {
	outFile.open(name.c_str());

	while (outFile.fail()) {
		std::cout << "\n\nERROR: Cannot save file to specified location. Please provide the correct path: ";
		std::cin >> name;
		outFile.open(name.c_str());
	}
}

void createClonedFile(std::ifstream &inFile, std::ofstream &outFile, std::string input) {
	getline(inFile, input);

	while (inFile) {
		outFile << input << std::endl;
		getline(inFile, input);
	}

	inFile.close();
	outFile.close();
}

void outro(std::string name) {
	std::cout << "\n\nThe new, cloned file has been created! Please check \'" << name << "\'." << std::endl << std::endl << std::endl;
}

bool repeat() {
	char decision;

	std::cout << "Would you like to copy another file? Type \'Y\' or \'y\' for yes\n";
	std::cout << "or \'N\' or \'n\' for no: ";
	std::cin >> decision;
	std::cout << std::endl;

	while (decision != 'Y' && decision != 'y' && decision != 'N' && decision != 'n') {
		std::cout << "Please enter a valid answer choice (\'Y\', \'y\', \'N\', or \'n\'): ";
		std::cin >> decision;
	}

	std::cout << std::endl;

	if (decision == 'Y' || decision == 'y') {
		return true;
	}
	else
		return false;
}

void goodBye() {
	std::cout << "Thank you for taking advantage of this program! Goodbye :)" << std::endl << std::endl;
}