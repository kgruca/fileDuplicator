// File Duplicator
// Name: Krzysztof Gruca
// takes a document specified by user and duplicates it at a location desired by user

#include <iostream>
#include <string>
#include <fstream>

// function declarations
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
	// ifstream object
	std::ifstream inputFile;
	// ofstream object 
	std::ofstream outputFile;
	// to hold the path to original file, path to duplicated file, and input read from original file, respectively
	std::string inputLoc, outputLoc, input;
	// store user's decision to duplicate another file or not
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

// intro explaining the purpose of fileDuplicator program to user
void intro() {
	std::cout << "Hello! I'm your personal assistant/file duplicator!" << std::endl;
	std::cout << "I will ask you a few questions pertaining to the file you wish to clone." << std::endl << std::endl;
}

/* ask user for path to the file they wish to duplicate
   returns the original's location back to main, to be stored in inputLoc variable */
std::string inputPath() {
	std::string inputLocation;

	std::cout << "First, please enter the path to the file that will be cloned: ";
	std::cin >> inputLocation;

	return inputLocation;
}

/* ask user for the file path to which new, duplicated file will be saved
   returns duplicated file's path back to main, to be stored to outputLoc variable */
std::string outputPath() {
	std::string outputLocation;

	std::cout << "\nNow, enter the name/path of the cloned file: ";
	std::cin >> outputLocation;

	return outputLocation;
}

/* open the file that will be duplicated
   catch error in opening file, if one should arise */
void openInput(std::ifstream &inFile, std::string name) {
	inFile.open(name.c_str());

	while (inFile.fail()) {
		std::cout << "\n\nERROR: Cannot open file. Please provide the correct path: ";
		std::cin >> name;
		inFile.open(name.c_str());
	}
}


/* create the file that will hold duplicated data
catch error in creating file, if one should arise */
void openOutput(std::ofstream &outFile, std::string name) {
	outFile.open(name.c_str());

	while (outFile.fail()) {
		std::cout << "\n\nERROR: Cannot save file to specified location. Please provide the correct path: ";
		std::cin >> name;
		outFile.open(name.c_str());
	}
}

/* write data from original file to duplicated file
   getline to read entire lines (with whitespaces) and copy them to new file
   while loop to process data until end of original file is reached
   close both files */
void createClonedFile(std::ifstream &inFile, std::ofstream &outFile, std::string input) {
	getline(inFile, input);

	while (inFile) {
		outFile << input << std::endl;
		getline(inFile, input);
	}

	inFile.close();
	outFile.close();
}

/* inform user of successful duplication 
   let them know of the path to the duplicated file*/
void outro(std::string name) {
	std::cout << "\n\nThe new, cloned file has been created! Please check \'" << name << "\'." << std::endl << std::endl << std::endl;
}

/* ask user if they would like to duplicate another file
   while statement for user's choice validation
   return user's choice to main */
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

/* thank user for using the program */
void goodBye() {
	std::cout << "Thank you for taking advantage of this program! Goodbye :)" << std::endl << std::endl;
}