#include "CSVReader.hpp"

int main ( int charc, char** argv )
{

    std::string filename = "C:\\dev\\csvreader\\sample_data\\cdr_StandAloneCluster_04_201601141231_120716.csv";
    CSVReader * csv = new CSVReader(filename);

    if ( !csv->is_open() )
        cout << "The file could not be opened" << endl;

    csv++;

    cout << &csv[0];

    cout << "Hello World" << endl;

    return 0;
}
