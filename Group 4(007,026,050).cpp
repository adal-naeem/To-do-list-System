#include <iostream>
#include <string>
using namespace std;

// Class to manage the to-do list
class TaskManager {
private:
    string tasks[20]; 
    int task_count; 

public:
    // Constructor to initialize task count
    TaskManager() {
        task_count = 0;
    }

    // Function within the class to add a new task
    void add_task() {
        if (task_count >= 20) {
            cout << "```TASK LIST IS FULL```" << endl;
        } else {
            cout << "Enter A New Task: ";
            cin.ignore();
            getline(cin, tasks[task_count]);
            task_count++;
            cout << "Task added successfully!" << endl;
        }
    }

    //function wihin the same class to print tasks
    void print_tasks() {
        cout << "Tasks To Do:" << endl;
        cout << "--------------------------------" << endl;
        for (int i = 0; i < task_count; i++) {
            cout << "Task " << i << " : " << tasks[i] << endl;
        }
        cout << "--------------------------------" << endl;
    }

    // Function within the same class to delete a task 
    void delete_task() {
        if (task_count == 0) {
            cout << "No tasks to delete!" << endl;
            return;
        }

        int del_task;
        cout << "Enter a task number to delete: ";
        cin >> del_task;

        if (del_task < 0 || del_task >= task_count) {
            cout << "Invalid task number!" << endl;
        } else {
            // Shift tasks to remove the deleted task
            for (int i = del_task; i < task_count-1; i++) {
                tasks[i] = tasks[i + 1];
            }
            task_count--;
            cout << "Task deleted successfully!" << endl;
        }
    }

};

int main() {
    TaskManager taskManager; // Object of TaskManager class
    int option = -1;

    while (option != 0) {
        // Display menu
        cout << "--- TO DO LIST ---" << endl;
        cout << "1 - To Add New Task" << endl;
        cout << "2 - To View Tasks" << endl;
        cout << "3 - Delete the Tasks" << endl;
        cout << "0 - Terminate the Program" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        // user's options
        switch (option) {
            case 1:
                taskManager.add_task();
                break;
            case 2:
                taskManager.print_tasks();
                break;
            case 3:
                taskManager.delete_task();
                break;
            case 0:
                cout << "Terminating the Program - --  ---   ----" << endl;
                break;
            default:
                cout << "You Entered Invalid Value!" << endl;
        }
    }

    return 0;
}
