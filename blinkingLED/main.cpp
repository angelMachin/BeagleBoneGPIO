#include<iostream>
#include<fstream>
#include<string>
#include <unistd.h>

using namespace std;

int main()
{
    cout << "using pin 12 (gpio 60)\n";

    enum Values {On = '1', Off = '0'} value = On;

    char valueFileName[] = "/sys/class/gpio/gpio60/value";
    char directionFileName[] = "/sys/class/gpio/gpio60/direction";

    ofstream ofs;
    ofs.open(directionFileName, ofstream::out | ofstream::trunc);
    if(!ofs.is_open())
    {
        cout << "cant open file " << directionFileName << endl;
        return -1;
    }
    ofs << "out";
    ofs.close();

    for(int i = 0; i < 10; i++)
    {
        ofs.open(valueFileName, ofstream::out | ofstream::trunc);
        ofs.put(value);
        ofs.close();

        usleep (1000000);

        value = value == On ? Off : On;
    }

    return 0;
}
