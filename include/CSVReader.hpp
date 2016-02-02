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
                std::getline( m_infile, tmpLine, '\n' );
                store_header(tmpLine);
            }

            int tr=0;
            while ( std::getline( m_infile, tmpLine, '\n' ) )
            {
                m_row.push_back ( tmpLine );
                tr++;
            }
            m_column_total=tr;

            m_row_itr = m_row.begin();
            header_map_itr = header_map.begin();

        }

        void set_double_quotes(bool flag)
        {
            m_double_quotes=true;
        }

        const row_iterator& itr() { return m_row_itr; }

        const std::string& operator[] ( int col )
        {
            current_column=col;
            parse_line_into_vec  ( m_row[current_row] );
            return m_tmp_line[col];
        }

        const row_iterator operator++(int)
        {
            current_row++;
            m_row_itr++;
            row_iterator * ri = &m_row_itr;
            return *ri;
        }

        const row_iterator& operator++()
        {
            current_row++;
            m_row_itr++;
            return m_row_itr;
        }

        const row_iterator& operator--()
        {
            current_row--;
            m_row_itr--;
            return m_row_itr;
        }

        const row_iterator operator--(int)
        {
            current_row--;
            m_row_itr--;
            row_iterator * ri = &m_row_itr;
            return *ri;
        }

        const std::string& get_data( unsigned int col ) { return m_tmp_line[col]; }

        row_iterator begin()
        {
            return m_row.begin();
        }

        row_iterator end()
        {
            return m_row.end();
        }

        bool is_open() {
            return m_infile.is_open();
        }

        std::string get_header(int col);

        int get_column_total() { return m_column_total; }
        int get_row_total() { return m_row_total; }



    private:

        void parse_line_into_vec (const std::string& str );
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
        int m_column_total;
        int m_row_total;
        bool m_double_quotes;
};

#endif // CSVREADER_H
