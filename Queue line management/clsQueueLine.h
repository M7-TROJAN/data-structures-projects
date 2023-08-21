#pragma once

#include <iostream>
#include <string>
#include "queue"
#include "stack"

class clsQueueLine
{
private:
    short _TotalTickets = 0;
    short _AverageServeTime = 0;
    std::string _Prefix = "";

    class clsTicket
    {
    private:
        short _Number = 0;
        std::string _Prefix;
        std::string _TicketTime;
        short _WaitingClients = 0;
        short _AverageServeTime = 0;
        short _ExpectedServeTime = 0;

        std::string _GetSystemDateTimeString()
        {
            // system datetime string
            time_t t = time(0);
            tm *now = localtime(&t);

            short Day, Month, Year, Hour, Minute, Second;

            Year = now->tm_year + 1900;
            Month = now->tm_mon + 1;
            Day = now->tm_mday;
            Hour = now->tm_hour;
            Minute = now->tm_min;
            Second = now->tm_sec;

            return (std::to_string(Day) + "/" + std::to_string(Month) + "/" + std::to_string(Year) + " - " + std::to_string(Hour) + ":" + std::to_string(Minute) + ":" + std::to_string(Second));
        }

    public:
        clsTicket(std::string Prefix, short Number, short WaitingClients, short AverageServeTime)
        {

            _Number = Number;
            _TicketTime = _GetSystemDateTimeString();
            _Prefix = Prefix;
            _WaitingClients = WaitingClients;
            _AverageServeTime = AverageServeTime;
        }

        std::string Prefix()
        {
            return _Prefix;
        }
        short Number()
        {
            return _Number;
        }

        std::string FullNumber()
        {
            return _Prefix + std::to_string(_Number);
        }

        std::string TicketTime()
        {
            return _TicketTime;
        }

        short WaitingClients()
        {
            return _WaitingClients;
        }

        short ExpectedServeTime()
        {
            return _AverageServeTime * _WaitingClients;
        }

        void Print()
        {
            std::cout << "\n\t\t\t  _______________________\n";
            std::cout << "\n\t\t\t\t    " << FullNumber();
            std::cout << "\n\n\t\t\t    " << _TicketTime;
            std::cout << "\n\t\t\t    Wattling Clients = " << _WaitingClients;
            std::cout << "\n\t\t\t      Serve Time In";
            std::cout << "\n\t\t\t       " << ExpectedServeTime() << " Minutes.";
            std::cout << "\n\t\t\t  _______________________\n";
        }
    };

public:
    std::queue<clsTicket> QueueLine;

    clsQueueLine(std::string Prefix, short AverageServeTime)
    {
        _Prefix = Prefix;
        _TotalTickets = 0;
        _AverageServeTime = AverageServeTime;
    }

    void IssueTicket()
    {
        _TotalTickets++;
        clsTicket Ticket(_Prefix, _TotalTickets, WaitingClients(), _AverageServeTime);
        QueueLine.push(Ticket);
    }

    int WaitingClients()
    {
        return QueueLine.size();
    }

    std::string WhoIsNext()
    {
        if (QueueLine.empty())
            return "No Clients Left.";
        else
            return QueueLine.front().FullNumber();
    }

    bool ServeNextClient()
    {
        if (QueueLine.empty())
            return false;

        QueueLine.pop();

        return true;
    }

    short ServedClients()
    {
        return _TotalTickets - WaitingClients();
    }

    void PrintInfo()
    {
        std::cout << "\n\t\t\t _____________________________\n";
        std::cout << "\n\t\t\t\tQueue Info";
        std::cout << "\n\t\t\t _____________________________\n";
        std::cout << "\n\t\t\t    Prefix            = " << _Prefix;
        std::cout << "\n\t\t\t    Total Tickets     = " << _TotalTickets;
        std::cout << "\n\t\t\t    Served Clients    = " << ServedClients();
        std::cout << "\n\t\t\t    Wattling Clients  = " << WaitingClients();
        ;
        std::cout << "\n\t\t\t _____________________________\n";
        std::cout << "\n";
    }

    void PrintTicketsLineRTL()
    {

        if (QueueLine.empty())
            std::cout << "\n\t\tTickets: No Tickets.";
        else
            std::cout << "\n\t\tTickets: ";

        // we copy the queue in order not to lose the original
        std::queue<clsTicket> TempQueueLine = QueueLine;

        while (!TempQueueLine.empty())
        {
            clsTicket Ticket = TempQueueLine.front();

            std::cout << " " << Ticket.FullNumber() << " <-- ";

            TempQueueLine.pop();
        }

        std::cout << "\n";
    }

    void PrintTicketsLineLTR()
    {
        if (QueueLine.empty())
            std::cout << "\n\t\tTickets: No Tickets.";
        else
            std::cout << "\n\t\tTickets: ";

        // we copy the queue in order not to lose the original
        std::queue<clsTicket> TempQueueLine = QueueLine;
        std::stack<clsTicket> TempStackLine;

        while (!TempQueueLine.empty())
        {
            TempStackLine.push(TempQueueLine.front());
            TempQueueLine.pop();
        }

        while (!TempStackLine.empty())
        {
            clsTicket Ticket = TempStackLine.top();

            std::cout << " " << Ticket.FullNumber() << " --> ";

            TempStackLine.pop();
        }
        std::cout << "\n";
    }

    void PrintAllTickets()
    {

        std::cout << "\n\n\t\t\t       ---Tickets---";

        if (QueueLine.empty())
            std::cout << "\n\n\t\t\t     ---No Tickets---\n";

        // we copy the queue in order not to lose the original
        std::queue<clsTicket> TempQueueLine = QueueLine;

        while (!TempQueueLine.empty())
        {
            TempQueueLine.front().Print();
            TempQueueLine.pop();
        }
    }
};
