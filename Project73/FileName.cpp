#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task {
public:
    string description;
    bool completed;
    Task(string desc) : description(desc), completed(false) {}
};

class ToDoList {
    vector<Task*> tasks;
public:
    void addTask(const string& desc) { tasks.push_back(new Task(desc)); }

    void listTasks() {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i]->completed) {
                cout << "[X] "; 
            }
            else {
                cout << "---";
                cout << "|";
            }
            cout << tasks[i]->description << endl;
        }
    }


    void taskCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1]->completed = true;
            cout << "Task marked as completed: " << tasks[index - 1]->description << endl;
        }
        else {
            cout << "Invalid task index." << endl;
        }
    }

    void addTask() {
        string desc;
        cout << "Enter the task you want to add:";
        getline(cin >> ws, desc);
        addTask(desc);
        cout << "Task added: " << desc << endl;
    }

    void taskCompleted() {
        size_t index;
        cout << "Enter the index of the task to mark as completed: ";
        cin >> index;
        taskCompleted(index);
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            delete tasks[index - 1];
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task removed successfully." << endl;
        }
        else {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask() {
        size_t index;
        cout << "Enter the index of the task to remove: ";
        cin >> index;
        removeTask(index);
    }

    void displayMenu() {
        cout << "Menu:" << endl;
        cout << "1. Add a task" << endl;
        cout << "2. Mark a task as completed" << endl;
        cout << "3. Remove a task" << endl;
        cout << "4. List tasks" << endl;
        cout << "5. Exit" << endl;
    }

    void handleMenu() {
        int choice;
        do {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();
            switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                taskCompleted();
                break;
            case 3:
                removeTask();
                break;
            case 4:
                listTasks();
                break;
            case 5:
                cout << "Exiting.....";
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 5);
    }

    ~ToDoList() {
        for (auto& task : tasks) delete task;
    }
};

int main() {
    ToDoList myList;
    myList.addTask("Finish Lab 3");
    myList.addTask("Study for exam");
    myList.addTask("Buy groceries");
    myList.addTask("Assignments");

    myList.handleMenu();

    return 0;
}
