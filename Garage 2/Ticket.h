#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED

class Ticket
{
    private:
        int entryDate;
        int departDate;

    public:
        Ticket()
        {entryDate = 4;} //example values

        int getTime()
        {
            departDate = 6;
            return departDate - entryDate;
        }
};

#endif // TICKET_H_INCLUDED
