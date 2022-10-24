#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED
#include "Ticket.h"
using namespace std;

class Vehicle
{
    private:
        string modelName;
        int ID;
        int modelYear;
        float length;
        float width;
        Ticket* carTicket;

    public:
        Vehicle(string main_Name = " ", int main_ID = 0, int main_Year = 0, float main_Length = 500, float main_Width = 200)
        {
            modelName = main_Name;
            ID = main_ID;
            modelYear = main_Year;
            length = main_Length;
            width = main_Width;
            carTicket = new Ticket;
        }

        int getTime()
        {return carTicket->getTime();}

        float getLength()
        {return length;}

        float getWidth()
        {return width;}

        void display()
        {cout << modelName << " " << ID << " " << modelYear << " " << length << " " << width << endl;}
};

#endif // VEHICLE_H_INCLUDED
