#ifndef CSVWRITER_H
#define CSVWRITER_H

#include <CSVReader.hpp>

using namespace std;

class CSVWriter
{
    public:

        CSVWriter ( CSVReader* csv, const std::string& filename ) : m_csv(csv)
        {
            outfile.open ( filename, ios::out );
        }

        void write_file ( const CSVReader::csv_map& write_map, int start_row=0 );
        void write_file ( int x, int y );
        void write_file ();
        void set_file_name ( const std::string& str ) { m_filename = str; }

private:
    void open_file();
    void save_file();

    CSVReader::csv_map m_map;
    std::ofstream outfile;
    CSVReader* m_csv;
    std::string m_filename;

};

#endif // CSVWRITER_H
