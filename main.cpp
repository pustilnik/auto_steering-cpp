#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#define PI 3.14159265
int main()
{
    std::string line, divisor = "; ", token;
    std::ifstream arquivo ("C:\\dev\\auto_steering-cpp\\attitude_exam.log");
    int time_stamp[5500], x[5500], y[5500], z[5500], counter=0, aux=1;
    float roll[5500], pitch[5500];
    size_t position = 0;


    if (arquivo.is_open())
    {
        while (getline(arquivo,line))
            {
            while((position = line.find(divisor)) != std::string::npos)
                {
                token = line.substr(0,position);
                switch(aux){

                    case 1:
                        time_stamp[counter] = stoi(token);
                        break;
                    case 2:
                        x[counter] = stoi(token);
                        break;
                    case 3:
                        y[counter] = stoi(token);
                        break;
                        }
                aux++;
                line.erase(0,position + divisor.length());
                }
            z[counter] = stoi(line);
            aux = 1;
            counter++;
               /* std::cout<<x[counter]<<"\t";
                std::cout<<y[counter]<<"\t";
                std::cout<<z[counter]<<"\n";*/


            }

        arquivo.close();

    }
    else
        {
        std::cout << "unable to open file";
        exit(-1);
        }

    for (int loop = 0; loop < sizeof(x); loop++)
    {

        roll[loop]= (atan2(y[loop],x[loop]))*180/PI;
        pitch[loop]=(atan2((-x[loop]),sqrt(pow(y[loop],2)+pow(z[loop],2))))*180/PI;
        std::cout << roll[loop]<<"\t";
        std::cout << pitch[loop]<<"\n";

    }

    return 0;
}
