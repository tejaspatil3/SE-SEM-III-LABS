#include <iostream>
#include <unordered_set>

using namespace std;

// Node structure to store student information
struct Student {
    int rollNumber;
    bool likesVanilla;
    bool likesButterscotch;
    Student* next;

    // Constructor to initialize values
    Student(int roll, bool vanilla, bool butterscotch) : rollNumber(roll), likesVanilla(vanilla), likesButterscotch(butterscotch), next(nullptr) {}
};

// Function to compute and display sets
void computeAndDisplaySets(Student* head) {
    unordered_set<int> bothLikesSet;
    unordered_set<int> eitherLikesSet;
    int neitherLikesCount = 0;

    while (head) {
        if (head->likesVanilla && head->likesButterscotch) {
            bothLikesSet.insert(head->rollNumber);
        }

        if (head->likesVanilla || head->likesButterscotch) {
            eitherLikesSet.insert(head->rollNumber);
        } else {
            neitherLikesCount++;
        }

        head = head->next;
    }

    // Displaying sets
    cout << "Students who like both Vanilla and Butterscotch:\n";
    for (int roll : bothLikesSet) {
        cout << roll << " ";
    }
    cout << "\n\n";

    cout << "Students who like either Vanilla or Butterscotch or not both:\n";
    for (int roll : eitherLikesSet) {
        cout << roll << " ";
    }
    cout << "\n\n";

    cout << "Number of students who like neither Vanilla nor Butterscotch: " << neitherLikesCount << "\n";
}

int main() {
    // Creating linked list representing the sets of students
    Student* head = new Student(101, true, false);
    head->next = new Student(102, false, true);
    head->next->next = new Student(103, true, true);
    head->next->next->next = new Student(104, false, false);

    // Displaying original sets
    cout << "Original Sets:\n";
    while (head) {
        cout << "Roll: " << head->rollNumber << ", Likes Vanilla: " << head->likesVanilla << ", Likes Butterscotch: " << head->likesButterscotch << "\n";
        head = head->next;
    }
    cout << "\n";

    // Computing and displaying sets
    computeAndDisplaySets(head);

    return 0;
}
