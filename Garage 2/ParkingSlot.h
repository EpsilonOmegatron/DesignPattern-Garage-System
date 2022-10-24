#ifndef PARKINGSLOT_H_INCLUDED
#define PARKINGSLOT_H_INCLUDED

using namespace std;

class ParkingSlot
{
    private:
        float length;
        float width;
        int payRate;
        bool isOccupied = 0;

    public:
        ParkingSlot(float main_Length = 500, float main_Width = 200, int main_Payrate = 10)
        {
            length = main_Length;
            width = main_Width;
            payRate = main_Payrate;
        }

        void setSlot()
        {
            cout << "Enter length: ";
            cin >> length;
            cout << "Enter width: ";
            cin >> width;
            cout << "Enter payrate: ";
            cin >> payRate;
        }

        int getPayrate()
        {return payRate;}

        float getLength()
        {return length;}

        float getWidth()
        {return width;}

        bool getOccupied()
        {return isOccupied;}

        void setOccupied(bool status)
        {isOccupied = status;}

        void display()
        {cout << length << " " << width << " " << isOccupied << endl;}
};

#endif // PARKINGSLOT_H_INCLUDED
