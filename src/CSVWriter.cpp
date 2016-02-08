#include <CSVWriter.hpp>

void CSVWriter::write_file( const CSVReader::csv_map& write_map )
{
    for ( auto c_itr = m_csv->begin(); c_itr != m_csv->end(); c_itr++, m_csv++ )
    {
        for ( auto itr = write_map.begin(); itr != write_map.end(); itr++ )
        {
            outfile << (*m_csv)[itr->first];
            if ( std::next(itr) != write_map.end() )
                outfile << ",";
        }
    }
}

void CSVWriter::write_file( int x, int y )
{

}

void CSVWriter::write_file()
{

}
