//cpp�� �� �� ���� ¥��
#include "boundary_statistics.h"


string UI::getInput(ifstream& inputFile)
{
    string inputString;
    getline(inputFile, inputString, ' ');  // Blank Compaction
    getline(inputFile, inputString, '\n');
    return inputString;
}

/*
 
 */
void UI::setOutput(ofstream& outputFile, string output)
{
    outputFile << output;
}