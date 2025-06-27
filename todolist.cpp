#include <iostream>
#include <vector>
#include <string>

using namespace std;
// Himanshu Garg - Todolist
struct Task {
    string description;
    bool completed;
};

// Function declarations
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markCompleted(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);

int main() {
    vector<Task> tasks;
    int choice;

    while (true) {
        cout << "\n===== TO-DO LIST MANAGER =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); // to ignore newline character after input

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting To-Do List Manager. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter task description: ";
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the list.\n";
        return;
    }

    cout << "\n--- Task List ---\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

void markCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to mark.\n";
        return;
    }

    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;

    if (index < 1 || index > static_cast<int>(tasks.size())) {
        cout << "Invalid task number.\n";
    } else {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed.\n";
    }
}

void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove.\n";
        return;
    }

    int index;
    cout << "Enter task number to remove: ";
    cin >> index;

    if (index < 1 || index > static_cast<int>(tasks.size())) {
        cout << "Invalid task number.\n";
    } else {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully.\n";
    }
}
