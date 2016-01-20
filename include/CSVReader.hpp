#ifndef CSVREADER_H
#define CSVREADER_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class CSVReader
{

    public:

        CSVReader ( const string& filename, bool dataHasHeaders=true )
        {
            infile.open( filename, 
        }

    private:
        ifstream* infile;
        vector<string> fileLines;
};

#endif // CSVREADER_H
