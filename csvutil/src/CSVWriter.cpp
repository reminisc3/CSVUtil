#include <CSVWriter.hpp>

void CSVWriter::write_file( const CSVReader::csv_map& write_map, int start_row )
{

    open_file();

    //print header
    for ( auto itr = write_map.begin(); itr != write_map.end(); itr++ )
    {
        outfile << itr->second;
        if ( std::next(itr) != write_map.end() )
            outfile << ",";
    }

    outfile << "\n";

    int current_row=0;
    for ( auto c_itr = m_csv->begin(); c_itr != m_csv->end(); c_itr++, (*m_csv)++ )
    {
        if ( start_row > current_row )
        {
            current_row++;
            continue;
        }

        for ( auto itr = write_map.begin(); itr != write_map.end(); itr++ )
        {
            outfile << (*m_csv)[itr->first];
            if ( std::next(itr) != write_map.end() )
                outfile << ",";
        }

        if ( std::next(c_itr) != m_csv->end() )
            outfile << "\n";
    }

    save_file();
}

void CSVWriter::write_file( int x, int y )
{
    open_file();

    int cols = m_csv->get_column_total();
    int rows = m_csv->get_row_total();

    //print header
    CSVReader::csv_map cmap = m_csv->get_header_map();
    for ( int z=y; z < cols; z++ )
    {
        outfile << cmap.at(z);

        if ( (z+1) < y )
            outfile << ",";
        else
            outfile << "\n";
    }

    m_csv->set_row(x);
    for ( unsigned int i=0; (i < x && i < rows); i++, (*m_csv)++ )
    {
        for ( unsigned int j=0; (j < y && j < y); j++ )
        {
            outfile << (*m_csv)[j];

            if ( (j+1) < y )
                outfile << ",";
            else
                outfile << "\n";
        }
    }

    save_file();
}

void CSVWriter::write_file()
{
    open_file();

}

void CSVWriter::open_file()
{
    if ( !outfile.is_open() )
        outfile.open( m_filename, ios::out );
}

void CSVWriter::save_file() {
    outfile.close();
}
