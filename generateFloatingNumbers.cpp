/**********************************************************************************************/
///
/// this file is the scr code to user number of files with each
///     file having a random number of generate floating numbers
///
/**********************************************************************************************/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

///
/// @brief main function
///
/// @param argc number of argumnet passed to the program; should be 2
/// @param argv char pointer argument passed to the program;
///         first should be the binary of the program
///         second should be number of files to generate
///
int main(int argc, char *argv[])
{

    // checking if argc is 2 or not
    if (argc != 2)
    {
        // /std::cout << argc << std::endl;
        std::cout << "Usage: ./<binary file name> <int>" << std::endl;
        return -1;
    }

    // assuming that user input a digit and it is single digit that is 1-9

    int fileNum = *(argv[1]) - 48;

    while (fileNum)
    {
        // creating the name of the file; structure is "randomFloatNum_<number>.txt"
        std::string fileName = "randomFloatNum_";
        fileName.append(std::to_string(fileNum));
        fileName.append(".txt");

        //creatig or opening the file
        std::ofstream myFile(fileName);

        // number of times to generate a number in a file; is between 0 to 1000
        int numRandGen = 1000 - (rand() / 1000);

        while (numRandGen)
        {
            // generating a float number
            float randNum = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);

            // adding the rand num to the file
            myFile << randNum;
            myFile << std::endl;

            --numRandGen;
        }

        // closing the file
        myFile.close();

        --fileNum;
    }

    return 0;
}