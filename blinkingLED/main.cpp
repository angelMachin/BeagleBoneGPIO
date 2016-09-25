#include<iostream>
#include<fstream>
#include<string>
#include <unistd.h>

using namespace std;

int main()
{
    cout << "using pin 28 (gpio 60)\n";

    ofstream ofs;

    char valueFileName[] = "/sys/class/gpio/gpio60/value";
    char directionFileName[] = "/sys/class/gpio/gpio60/direction";

    ofs.open(directionFileName, ofstream::out | ofstream::trunc);
    ofs << "out";
    ofs.close();

    for(int i = 0; i < 10; i++)
    {
        ofs.open(valueFileName, ofstream::out | ofstream::trunc);
        ofs << "1";
        ofs.close();

        usleep (1000000);

        ofs.open(valueFileName, ofstream::out | ofstream::trunc);
        ofs << "0";
        ofs.close();

        usleep (1000000);
    }

    ofs.close();
    return 0;
}
