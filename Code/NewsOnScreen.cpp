// NewsOnScreen subscription system with    ->   observer design pattern




#include <iostream>
#include <list>                         // header for list
#include <string>                       // header for string
using namespace std;


// interfaces
class Observer
{
public:
    virtual void Update(const string &message_from_subject) = 0;
    virtual bool matchSubscriber(const int id) = 0;
};

class Subject
{
public:
    virtual void subscribeClient(Observer *observer) = 0;
    virtual void unsubscribeClient(Observer *observer) = 0;
    virtual void notifyAllSubscribers() = 0;
    virtual void findSubscriber() = 0;
};





// Service class extends Subject public interface
class Service : public Subject
{
// fucntion of this Service class which is public
public:
    // Subscription management method
    void subscribeClient(Observer *observer) override
    {
        subscriberList.push_back(observer);                                     // adding object to list
    }

    void unsubscribeClient(Observer *observer) override
    {
        subscriberList.remove(observer);                                       // removing object form list
    }

    void notifyAllSubscribers() override
    {

        std::list<Observer *>::iterator itr;
        cout << "\n--------------------------NewsOnScreen--------------------------";
        cout << "\n--------------------------VLE Blackboard--------------------------\n\n";
        for(itr = subscriberList.begin(); itr != subscriberList.end(); ++itr)
        {
            (*itr)->Update(announcement);                                                           // calling Update() function of Subscriber class with string parameter
        }

    }

    void findSubscriber() override
    {
        bool isMatched = false;
        std::list<Observer *>::iterator itr;                                                        // list iterator
        for(itr = subscriberList.begin(); itr != subscriberList.end(); ++itr)
        {
            isMatched = (*itr)->matchSubscriber(ID);                                               // calling matchSubscriber() function of Subscriber class which will return bool value

            if(isMatched == true)
                break;
        }

    }

    void createAnnouncement(std::string message = "Empty")
    {
        this->announcement = message;                                   // initializing variables value
        notifyAllSubscribers();                                         // calling notifyAllSubscriber() function of this class
    }

    void removeSubscriber(int sID)
    {
        this->ID = sID;                                                 // initializing value
        findSubscriber();                                               // calling findSubscriber() function
    }

    void HowManyObserver()
    {
        cout << "\nThere are " << subscriberList.size() << " subscribers in the service.\n";                                    // printing value of list of subscriber
    }


// private variables
private:
    std::list<Observer *> subscriberList;
    string announcement;
    int ID;
};




// Subscriber class extends Observer public interface
class Subscriber : public Observer
{
// fucntion of this Service class which is public
public:
    // constructor
    Subscriber(Service &service) : service_(service)
    {
        this->service_.subscribeClient(this);                           // calling subscribeClient function of Service class
        cout << "ID:" << ++Subscriber::static_number_;
        this->number_ = Subscriber::static_number_;                     // initializing number variable
    }

    void Update(const std::string &message_from_service) override
    {
        message_from_service_ = message_from_service;               // initializing variables value
        PrintInfo();                                                // calling printInfo() function of this Subscriber class
    }

    bool matchSubscriber(const int id) override
    {
        if(this->number_ == id)
            {
                RemoveMeFromTheList();                      // calling RemoveMeFromTheList() function of Subscriber class
                return true;                                // returning value
            }
        else
            return false;                                   // returning value
    }

    void RemoveMeFromTheList()
    {
        service_.unsubscribeClient(this);                                       // callling ununsubscribeClient of Service class through object
        cout << this->name << " ID: " << this->number_ << ", unsubscribed this service.\n";          // printing value
    }

    void PrintInfo()
    {
        // print some value
        cout << "Subscriber name: " << this->name << ", ID:" << this->number_ << " => a new message is available --> " << this->message_from_service_ << "\n";
    }

    void setName(string uName)
    {
        this->name = uName;                     // intializing value of a variable
    }


// some private variable
private:
    string message_from_service_;
    Service &service_;
    static int static_number_;
    int number_;
    string name = " ";
};


// Initialize pointer to zero so that it can be initialized in first call to getInstance
int Subscriber::static_number_ = 0;




// Display class to print some info
class Display
{
public:
// Administrator function
void Administrator()
{
    cout << "\n\n";
                cout << "--------------------------NewsOnScreen--------------------------\n\n";
                cout << "1. How many subscribers are there in this service?\n";
                cout << "2. Make an Announcement.\n";
                cout << "3. Go back.\n";
                cout << "\nEnter your number: ";
}

// Client function
void Client()
{
cout << "\n\n";
                cout << "--------------------------NewsOnScreen--------------------------n\n";
                cout << "1. Subscribe NewsOnScreen service.\n";
                cout << "2. Unsubscribe NewsOnScreen service.\n";
                cout << "3. Go back.\n";
                cout << "\nEnter your number: ";
}

// Blackboard function
void Blackboard()
{
    system("CLS");
        cout << "--------------------------NewsOnScreen--------------------------\n\n";
        cout << "1. Client.\n";
        cout << "2. Administrator.\n";
        cout << "3. Exit.\n";
        cout << "\nEnter your number: ";
}

};




// main function
int main()
{


    //by default we are making some subscriber
    Service *service = new Service;
    Subscriber *subscriber1 = new Subscriber(*service);
    subscriber1->setName("Srijon");
    Subscriber *subscriber2 = new Subscriber(*service);
    subscriber2->setName("Sijan");
    Subscriber *subscriber3 = new Subscriber(*service);
    subscriber3->setName("Suhel");
    Subscriber *subscriber4 = new Subscriber(*service);
    subscriber4->setName("Tahmid");
    Subscriber *subscriber5 = new Subscriber(*service);
    subscriber5->setName("Sakib");
    Subscriber *subscriber6 = new Subscriber(*service);
    subscriber6->setName("Oly");

    //creating Display class object to print some info
    Display *display = new Display();


    while (true)
    {
        
        display->Blackboard();                                                    // calling Blackboard() function to print some info
        int opn;
        cin >> opn;


        if (opn == 1)
        {
            while (true)
            {

                display->Client();                                                   // calling Client() function to print some info
                int opn;
                cin >> opn;

                if (opn == 1)
                {
                    cout << "Enter your name? (small letter)\n";
                    cout << "Name: ";
                    string name;

                    // taking input of string
                    getline(cin >> ws, name);                                               // Usage of std::ws will extract all the whitespace character

                    cout << endl << name << " subscribed NewsOnScreen service. Your ";
                    Subscriber *subscriber = new Subscriber(*service);                      // adding Subscriber through creating object of Subscriber class with object of pointer of Service class object
                    subscriber->setName(name);                                              // calling setName() method of Subscriber to set name through passing string parameter
                    //Subscriber *name = new Subscriber(*service);
                }
                else if (opn == 2)
                {
                    cout << "Enter your ID: ";
                    int ID;
                    cin >> ID;
                    service->removeSubscriber(ID);                                             // calling removeSubscriber() function of Service class with int parameter
                }
                else if (opn == 3)
                {
                    break;
                }
                else
                    cout << "\nPlease enter correct number.\n";
            }
        }

        else if (opn == 2)
        {
            while (true)
            {

                display->Administrator();                                                        // calling Administrator() function to print some info
                int opn;
                cin >> opn;

                if (opn == 1)
                {
                    service->HowManyObserver();                                         // calling HowManyObserver() function of Service class to know the number of subscriber
                }
                else if (opn == 2)
                {

                    cout << "Enter your announcement: \n";
                    string notice;

                    // Usage of std::ws will extract all the whitespace character
                    getline(cin >> ws, notice);

                    service->createAnnouncement(notice);                                // calling createAnnouncement() function of Service class to create an announcement
                }
                else if (opn == 3)
                {
                    break;
                }
                else
                    cout << "\nPlease enter correct number.\n";
            }
        }


        else if (opn == 3)
            return 0;
        else
            cout << "\nPlease enter correct number.\n";
    }



}
