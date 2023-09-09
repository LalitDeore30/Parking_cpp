#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string vehicle_type;
    string vehicle_name;
    int vehicle_number;
    Node *next;

    Node(string type, string name, int number) : vehicle_type(type), vehicle_name(name), vehicle_number(number), next(nullptr) {}
};
class Society
{
private:
    string sName;
    bool bParking_Allocated;
    int iWing_Number;

protected:
    int iFlat_Number;
    long Phone_Number, Alternate_Number;
};
class Parking : public Society
{
public:
    Node *head = nullptr;
    Node *tail = nullptr;
    int parkingSize = 6;

    Parking() : head(nullptr), tail(nullptr) {}

    void insertAtEnd(string type, string name, int number)
    {
        if (size() >= parkingSize)
        {
            cout << "Parking is full. Cannot park more vehicles." << endl;
            return;
        }

        Node *newNode = new Node(type, name, number);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void exitParking(int vehicleNumber)
    {
        Node *current = head;
        Node *prev = nullptr;

        while (current != nullptr)
        {
            if (current->vehicle_number == vehicleNumber)
            {
                if (prev != nullptr)
                {
                    prev->next = current->next;
                }
                else
                {
                    head = current->next;
                }
                delete current;
                cout << "Vehicle with Number Plate " << vehicleNumber << " has exit from the parking." << endl;
                return;
            }
            prev = current;
            current = current->next;
        }

        cout << "Vehicle with Number Plate " << vehicleNumber << " not found in the parking." << endl;
    }

    int size()
    {
        int count = 0;
        Node *current = head;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    void display()
    {
        Node *temp = head;
        cout << "Parking List:" << endl;
        while (temp != nullptr)
        {
            cout << "Vehicle Type: " << temp->vehicle_type << endl;
            cout << "Vehicle Name: " << temp->vehicle_name << endl;
            cout << "Vehicle Number (Number Plate): " << temp->vehicle_number << endl;
            cout << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    Parking parking;
    int choice;

    while (true)
    {
        cout << "******** WELCOME TO MANGALAM SOCIETY ********" << endl;
        cout << "Parking Menu" << endl;
        cout << "1. Park a vehicle" << endl;
        cout << "2. Exit parking" << endl;
        cout << "3. Display parking list" << endl;
        cout << "4. Check how many vehicles are parked in the parking are" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string type, name;
            int number;
            cout << "Enter Vehicle Type: ";
            cin >> type;
            cout << "Enter Vehicle Name: ";
            cin >> name;
            cout << "Enter Vehicle Number (Number Plate): ";
            cin >> number;
            parking.insertAtEnd(type, name, number);
            cout << "Vehicle parked successfully." << endl;
            break;
        }
        case 2:
        {
            int number;
            cout << "Enter Vehicle Number (Number Plate) to exit from parking: ";
            cin >> number;
            parking.exitParking(number);
            break;
        }
        case 3:
            parking.display();
            break;
        case 4:
            cout << "Number of vehicles parked: " << parking.size() << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
