#ifndef SLOTSELECTION_H_INCLUDED
#define SLOTSELECTION_H_INCLUDED

class SlotSelection
{
    virtual bool selectSlot(ParkingSlot[], Vehicle[], int, Vehicle) = 0;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class FirstFit: public SlotSelection
{
    private:
        bool possible = 0;

    public:
        bool selectSlot(ParkingSlot p[], Vehicle v[], int size, Vehicle mainV)
        {
            for(int i = 0; i < size; i++)
            {
                if(p[i].getOccupied() == 0)
                {
                    if(mainV.getLength() > p[i].getLength() || mainV.getWidth() > p[i].getWidth())
                    {possible = 0;}
                    else
                    {
                        v[i] = mainV;
                        p[i].setOccupied(1);
                        possible = 1;
                        return possible;
                    }
                }
            }
            return possible;
        }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class BestFit: public SlotSelection
{
    private:
        ParkingSlot minimum;
        int minSlot;
        bool possible = 0;

    public:
        bool selectSlot(ParkingSlot p[], Vehicle v[], int size, Vehicle mainV)
        {
            for(int i = 0; i < size; i++)
            {
                if(p[i].getOccupied() == 0)
                {
                    if(mainV.getLength() > p[i].getLength() || mainV.getWidth() > p[i].getWidth())
                    {possible = 0;}
                    else
                    {
                        if(mainV.getLength() < p[i].getLength() && mainV.getWidth() < p[i].getWidth())
                        {
                            if(p[i].getLength() <= minimum.getLength() && p[i].getWidth() <= minimum.getWidth())
                            {
                                minimum = p[i];
                                minSlot = i;
                                possible = 1;
                            }
                        }
                    }
                }
            }

            if(possible == 1)
            {v[minSlot] = mainV; p[minSlot].setOccupied(1);}

            return possible;
        }
};

#endif // SLOTSELECTION_H_INCLUDED
