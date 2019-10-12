#include "line.hpp"
#define PI 3.14159265

int main()
{
    std::string line, divisor = "; ", token;
    std::ifstream arquivo ("attitude_exam.log");
    unsigned int TAM_MAX;
    size_t position = 0;

    if (arquivo.is_open())
    {
        TAM_MAX = numberoflines(arquivo);
        if (TAM_MAX)
            {
            arquivo.close();

            int time_stamp[TAM_MAX], x[TAM_MAX], y[TAM_MAX], z[TAM_MAX], counter=0, aux=1;
            float roll[TAM_MAX], pitch[TAM_MAX];
            arquivo.open("attitude_exam.log");
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
                }
            arquivo.close();
            // creating new file
            std::ofstream arquivo_out ("roll_and_pitch_angles.txt");

            if (arquivo_out.is_open())
                {
                arquivo_out << "Stamp\tRoll\tPitch\n";
                }
            for (unsigned int loop = 0; loop < TAM_MAX; loop++)
                {

                roll[loop]= (atan2(y[loop],x[loop]))*180/PI;
                pitch[loop]=(atan2((-x[loop]),sqrt(pow(y[loop],2)+pow(z[loop],2))))*180/PI;
                arquivo_out << time_stamp[loop]<<"\t";
                arquivo_out << std::fixed << std::setprecision(2)<<roll[loop]<<"\t";
                arquivo_out << std::fixed << std::setprecision(2)<<pitch[loop]<<"\n";

                }
            arquivo_out.close();
            std::cout << "Everything is fine! look for the roll_and_pitch_angles text created!";
            }
    }
    else
        {
        std::cout << "unable to open file";
        exit(-1);
        }



    return 0;
}

int numberoflines(std::ifstream& x)
{
    unsigned int counter = 0;
    std::string receiver;

    while (getline(x,receiver))
    {

        counter++;
    }
    return counter;
}
