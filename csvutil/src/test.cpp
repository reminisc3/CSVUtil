#include <CSVReader.hpp>
#include <CSVWriter.hpp>

int main ( int charc, char** argv )
{

    std::string filename = "C:\\dev\\csvreader\\sample_data\\cdr_StandAloneCluster_04_201601141231_120716.csv";
    //std::string filename = "/home/kyle/git/CSVReader/sample_data/cdr_StandAloneCluster_04_201601141231_120716.csv";
    CSVReader csv (filename);

    if ( !csv.is_open() )
        cout << "The file could not be opened" << endl;

    /* write new csv with a map */
    CSVWriter out_csv( &csv, "sample.csv" );
    CSVReader::csv_map csv_map = {
        {0, "cdrRecordType"},
        {1,"globalCallID_callManagerId"},
        {2,"globalCallID_callId"},
        {3,"origLegCallIdentifier"},
        {4,"dateTimeOrigination"},
        {5,"origNodeId"},
        {7,"origIpAddr"},
        {8,"callingPartyNumber"},
        {11,"origCause_value"},
        {25,"destLegCallIdentifier"},
        {26,"destNodeId"},
        {28,"destIpAddr"},
        {29,"originalCalledPartyNumber"},
        {33,"destCause_value"},
        {47,"dateTimeConnect"},
        {48,"dateTimeDisconnect"},
        {50,"pkid"},
        {53,"finalCalledPartyNumberPartition"},
        {55,"duration"},
        {56,"origDeviceName"},
        {57,"destDeviceName"},
        {58,"origCallTerminationOnBehalfOf"},
        {59,"destCallTerminationOnBehalfOf"},
        {66,"joinOnBehalfOf"},
        {80,"origIpv4v6Addr"},
        {81,"destIpv4v6Addr"}
    };

    out_csv.write_file( csv_map, 1 );

    return 0;
}
