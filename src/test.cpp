#include "CSVReader.hpp"

int main ( int charc, char** argv )
{

    std::string filename = "C:\\dev\\csvreader\\sample_data\\cdr_StandAloneCluster_04_201601141231_120716.csv";
    //std::string filename = "/home/kyle/git/CSVReader/sample_data/cdr_StandAloneCluster_04_201601141231_120716.csv";
    CSVReader csv (filename);

    if ( !csv.is_open() )
        cout << "The file could not be opened" << endl;

    int cols = csv.get_column_total();

    for ( auto itr=csv.itr(); itr != csv.end(); itr++, csv++ )
    {
        for ( int i=0; i < cols; i++ )
        {
            cout << (csv[i] == "" ? "NULL" : csv[i]);
            if ( i+1 != cols )
                cout << ",";
            else
                cout << endl;
        }
    }

    return 0;
}
