#ifndef CSVWRITER_H
#define CSVWRITER_H

#include <CSVReader.hpp>

class CSVWriter
{
    public:

        CSVWriter ( CSVReader* csv, const std::string& outfile ) : m_csv(csv)
        {

        }

        void write_file ( const CSVReader::csv_map& write_map );
        void write_file ( int x, int y );
        void write_file ();

private:
    CSVReader::csv_map m_map;
    std::ofstream outfile;
    CSVReader* m_csv;


};

#endif // CSVWRITER_H
