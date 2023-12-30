#include <iostream>
#include <vector>

using namespace std;

struct ToDoItem {
  string description;
  bool isCompleted;
};

int main() {
  vector<ToDoItem> toDoList;

  while (true) {
    int choice;

    cout << "\n** To-Do List **" << endl;
    cout << "1. Add a task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Mark task as completed" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1: {
        ToDoItem item;
        cout << "Enter the task description: ";
        cin.ignore();
        getline(cin, item.description);
        item.isCompleted = false;
        toDoList.push_back(item);
        cout << "Task added successfully!" << endl;
        break;
      }
      case 2: {
        cout << "\n** Current Tasks **" << endl;
        for (int i = 0; i < toDoList.size(); i++) {
          cout << i + 1 << ". " << toDoList[i].description << " (" << (toDoList[i].isCompleted ? "Completed" : "Incomplete") << ")" << endl;
        }
        if (toDoList.empty()) {
          cout << "No tasks to display." << endl;
        }
        break;
      }
      case 3: {
        int taskNumber;
        cout << "Enter the number of the task to mark as completed: ";
        cin >> taskNumber;
        if (taskNumber < 1 || taskNumber > toDoList.size()) {
          cout << "Invalid task number." << endl;
          break;
        }
        toDoList[taskNumber - 1].isCompleted = true;
        cout << "Task marked as completed." << endl;
        break;
      }
      case 4: {
        cout << "Exiting..." << endl;
        return 0;
      }
      default: {
        cout << "Invalid choice." << endl;
        break;
      }
    }
  }

  return 0;
}
