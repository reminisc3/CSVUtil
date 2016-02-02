#include "CSVReader.hpp"

void CSVReader::store_header(const std::string& str )
{
    std::istringstream iss ( str );
    std::string col;
    int i=0;
    while ( std::getline(iss, col, ',' ) )
    {
        header_map.insert( std::pair<int,std::string>(i, col) ); //store in map
        i++;
    }
    m_column_total=i;
}

std::string CSVReader::get_header( int col )
{
    return header_map[col];
}

void CSVReader::parse_line_into_vec ( const std::string& line )
{
    m_tmp_line.clear(); //clear temp storage
    std::string tmp;
    std::istringstream iss(line);
    if ( !m_double_quotes )
    {
        while ( std::getline(iss,tmp,',') ) {
            m_tmp_line.push_back( tmp );
        }
    }
    else
    {
        //add support for double quoted data here
    }

}
