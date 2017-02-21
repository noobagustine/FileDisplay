#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    const unsigned short MAX_LINES = 24;

    ifstream in_file;
    string filename;
    string in_str;

    bool exit = false;
    unsigned line_number = 0;

    cout << "Enter the name of a file: ";
    getline( cin, filename );

    in_file.open( filename.c_str() );
    if ( ! in_file.fail() )
    {
        cout << "To continue press any key to exit press 'q'";
        cout << endl;

        while ( getline( in_file, in_str ) && ! exit )
        {
            cout << in_str;
            cout << endl;

            line_number++;
            if ( line_number % MAX_LINES == 0 )
            {
                if ( cin.get() == 'q' )
                {
                    exit = true;
                }
            }
        }
    }

    cin.ignore();
    cout << "Press <ENTER> to exit ";
    cin.get();
    return 0;
}
