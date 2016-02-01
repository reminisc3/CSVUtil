#ifndef CSVREADER_H
#define CSVREADER_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

class CSVReader
{

    public:

        typedef std::vector<std::string>::iterator row_iterator;

        CSVReader ( const string& filename, bool header=true ) : current_row(0),
                                                                 m_double_quotes(false)
        {

            m_header=header;

            std::string tmpLine;
            int line_num=0;
            m_infile.open( filename.c_str(), ios::in );

            if ( header )
            {
                std::getline( m_infile, tmpLine );
                store_header(tmpLine);
            }

            while ( std::getline( m_infile, tmpLine, '\n' ) )
            {
                //store lines in vector
                m_row.push_back ( tmpLine );
            }

            m_row_itr = m_row.begin();
            header_map_itr = header_map.begin();

        }

        void set_double_quotes(bool flag)
        {
            m_double_quotes=true;
        }

        const row_iterator& itr() { return m_row_itr; }

        template <class t>
        const t& operator[] ( int col )
        {
            cout << "test1";
            current_column=col;
            return m_row[col];
        }

        template <class t>
        t operator[] ( int col )
        {
            cout << "test1";
            current_column=col;
            return m_row[col];
        }

        void operator++()
        {
            current_row++;
            m_row_itr++;
        }

        void operator--()
        {
            current_row--;
            m_row_itr--;
        }

        const std::string& get_data( unsigned int col ) { return m_tmp_line[col]; }

        const row_iterator& begin()
        {
            return m_row.begin();
        }

        const row_iterator& end()
        {
            return m_row.end();
        }

        bool is_open() {
            return m_infile.is_open();
        }

        std::string get_header(int col);

        std::vector<std::string> parse_line_into_vec (const std::string& str );

    private:

        void store_header( const string& str );
        std::map<int,std::string> header_map;
        std::map<int,std::string>::iterator header_map_itr;
        bool m_header;
        ifstream m_infile;
        std::vector<std::string> m_tmp_line;
        std::vector<std::string> m_row;
        row_iterator m_row_itr;
        int current_row;
        int current_column;
        bool m_double_quotes;
};

#endif // CSVREADER_H
