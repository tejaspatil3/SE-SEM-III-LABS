#include <iostream>
#include <cstring>

using namespace std;

// Node structure to store student information
struct Student {
    int prn;
    char name[50];
    Student* next;
};

// Linked list class for managing club members
class ClubList {
private:
    Student* head;

public:
    // Constructor
    ClubList() : head(nullptr) {}

    // Function to add a member to the club
    void addMember(int prn, const char* name) {
        Student* newMember = new Student{prn, "", nullptr};
        strcpy(newMember->name, name);

        if (!head) {
            head = newMember;
        } else {
            newMember->next = head;
            head = newMember;
        }
    }

    // Function to delete a member from the club
    void deleteMember(int prn) {
        if (!head) {
            cout << "Club is empty.\n";
            return;
        }

        if (head->prn == prn) {
            Student* temp = head;
            head = head->next;
            delete temp;
            cout << "Member with PRN " << prn << " deleted.\n";
            return;
        }

        Student* current = head;
        while (current->next && current->next->prn != prn) {
            current = current->next;
        }

        if (current->next) {
            Student* temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << "Member with PRN " << prn << " deleted.\n";
        } else {
            cout << "Member with PRN " << prn << " not found.\n";
        }
    }

    // Function to compute the total number of members
    int getTotalMembers() {
        int count = 0;
        Student* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Function to display all members
    void displayMembers() {
        if (!head) {
            cout << "Club is empty.\n";
            return;
        }

        cout << "Club Members:\n";
        Student* current = head;
        while (current) {
            cout << "PRN: " << current->prn << ", Name: " << current->name << "\n";
            current = current->next;
        }
    }

    // Function to concatenate two lists
    void concatenateLists(ClubList& otherList) {
        if (!head) {
            head = otherList.head;
        } else {
            Student* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = otherList.head;
        }

        otherList.head = nullptr; // Prevents otherList destructor from deleting nodes
    }
};

int main() {
    // Creating two linked lists for two divisions
    ClubList division1, division2;

    // Adding members to the first division
    division1.addMember(111, "John");
    division1.addMember(112, "Alice");
    division1.addMember(113, "Bob");

    // Adding members to the second division
    division2.addMember(211, "Charlie");
    division2.addMember(212, "Diana");
    division2.addMember(213, "Eve");

    // Displaying members of each division
    cout << "Division 1 Members:\n";
    division1.displayMembers();

    cout << "\nDivision 2 Members:\n";
    division2.displayMembers();

    // Concatenating the two divisions
    division1.concatenateLists(division2);

    // Displaying the concatenated list
    cout << "\nConcatenated Members:\n";
    division1.displayMembers();

    // Deleting a member from the concatenated list
    division1.deleteMember(112);

    // Displaying the updated list
    cout << "\nUpdated Members:\n";
    division1.displayMembers();

    return 0;
}