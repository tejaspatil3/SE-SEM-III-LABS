#include <iostream>
#include <queue>

using namespace std;

// Function to add a job to the queue
void addJob(queue<string>& jobQueue, const string& job) {
    jobQueue.push(job);
    cout << "Job added to the queue: " << job << "\n";
}

// Function to delete a job from the front of the queue
void deleteJob(queue<string>& jobQueue) {
    if (!jobQueue.empty()) {
        cout << "Job deleted from the queue: " << jobQueue.front() << "\n";
        jobQueue.pop();
    } else {
        cout << "Queue is empty. No job to delete.\n";
    }
}

// Function to display the current jobs in the queue
void displayJobs(const queue<string>& jobQueue) {
    cout << "Current Jobs in the Queue:\n";
    queue<string> tempQueue = jobQueue; // Create a copy for display without modifying the original
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << "\n";
        tempQueue.pop();
    }
    cout << "\n";
}

int main() {
    queue<string> jobQueue;

    // Adding jobs to the queue
    addJob(jobQueue, "Job1");
    addJob(jobQueue, "Job2");
    addJob(jobQueue, "Job3");

    // Displaying current jobs
    displayJobs(jobQueue);

    // Deleting a job
    deleteJob(jobQueue);

    // Displaying updated jobs
    displayJobs(jobQueue);

    // Adding more jobs
    addJob(jobQueue, "Job4");
    addJob(jobQueue, "Job5");

    // Displaying final jobs
    displayJobs(jobQueue);

    return 0;
}

