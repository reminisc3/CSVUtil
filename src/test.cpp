#include "CSVReader.hpp"

int main ( int charc, char** argv )
{

    //std::string filename = "C:\\dev\\csvreader\\sample_data\\cdr_StandAloneCluster_04_201601141231_120716.csv";
    std::string filename = "/home/kyle/git/CSVReader/sample_data/cdr_StandAloneCluster_04_201601141231_120716.csv";
    CSVReader csv (filename);

    if ( !csv.is_open() )
        cout << "The file could not be opened" << endl;

    for ( auto itr=csv.itr(); itr != csv.end(); itr++, csv++ )
    {
        cout << csv[0] << endl; //print first column
    }

    return 0;
}
