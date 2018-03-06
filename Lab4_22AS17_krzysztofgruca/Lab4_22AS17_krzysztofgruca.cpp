// CIS 22A
// Lab 04 - Filestream operations
// Name: Krzysztof Gruca

/* Pseudocode
   
   define ifstream object to open the file to be cloned and read its data

   define ofstream object to write the newly cloned file

   define three string variables: one for the path tp the existing file, one for a
   path to the new file, and one to store the data from the existing file

   output info to user, letting them know that the program is useful to create duplicate files

   ask the user for path to the file that they wish to clone

   ask for the specified path where the file clone should be saved

   while input path fails
      error message
	  input the correct path

   while the output path fails
      error message
	  input correct path
   
   getline(original file, first line of text)

   while the input file still has data to write to the new file
      write data to new file
	  getline(original file, next line of text)

  close the original file
  close the cloned file

  system pause
  return 0

 */


#include <iostream>
#include <string>
#include <fstream>

int main() {

	std::ifstream inputFile;
	std::ofstream outputFile;
	std::string inputLoc, outputLoc, input;

	std::cout << "Hello! I'm your personal assistant/file duplicator!" << std::endl;
	std::cout << "I will ask you a few questions pertaining to the file you wish to clone." << std::endl << std::endl;

	std::cout << "First, please enter the path to the file that will be cloned: ";
	std::cin >> inputLoc;

	std::cout << "\nNow, enter the name/path of the cloned file: ";
	std::cin >> outputLoc;

	inputFile.open(inputLoc.c_str());
	outputFile.open(outputLoc.c_str());

	while (inputFile.fail()) {
		std::cout << "\n\nERROR: Cannot open file. Please provide the correct path: ";
		std::cin >> inputLoc;
		inputFile.open(inputLoc.c_str());	
	}

	while (outputFile.fail()) {
		std::cout << "\n\nERROR: Cannot save file to specified location. Please provide the correct path: ";
		std::cin >> outputLoc;
		outputFile.open(outputLoc.c_str());	
	}

	getline(inputFile, input);

	while (inputFile) {
		outputFile << input << std::endl;
		getline(inputFile, input);
	}

	inputFile.close();
	outputFile.close();

	std::cout << "\n\nThe new, cloned file has been created! Please check \'" << outputLoc << "\'." << std::endl << std::endl <<std::endl;

	system("pause");
	return 0;
}