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
}

std::string CSVReader::get_header( int col )
{
    return header_map[col];
}

std::vector<std::string> CSVReader::parse_line_into_vec ( const std::string& line )
{
    std::vector<std::string> vec;
    std::string tmp;
    std::istringstream iss(line);
    if ( !m_double_quotes )
    {
        while ( std::getline(iss,tmp,',') ) {
            vec.push_back( tmp );
        }
    }
    else
    {
        //add support for double quoted data here
    }

    return vec;

}
