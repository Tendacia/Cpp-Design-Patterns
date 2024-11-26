/**
 * @file mvc.cpp
 * @brief This is a simple example of the Model-View-Controller (MVC) design
 * @author Tendacia
 * @date 2024-11-26
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Model class for the Task
 *        This class is responsible for the data of the Task
 *
 */
class TaskModel {
private:
  vector<string> tasks;

public:
  void addTask(string task) { tasks.push_back(task); }

  void removeTask(int index) { tasks.erase(tasks.begin() + index); }

  vector<string> getTasks() { return tasks; }

  void clearTasks() { tasks.clear(); }
};

/**
 * @brief View class for the Task
 *        This class is responsible for the UI of the Task
 *
 */

class TaskView {
public:
  void Render(const vector<string> &tasks) {
    cout << "Tasks: " << endl;
    for (int i = 0; i < tasks.size(); i++) {
      cout << i + 1 << ". " << tasks[i] << endl;
    }
  }
};

/**
 * @brief Controller class for the Task
 *        This class is responsible for the communication between Model and
 * View, and also the business logic
 *
 */

class TaskController {
private:
  TaskModel &model;
  TaskView &view;

public:
  TaskController(TaskModel &model, TaskView &view) : model(model), view(view) {}
  void addTask(string task) {
    model.addTask(task);
    updateView();
  }

  void removeTask(int index) {
    model.removeTask(index);
    updateView();
  }

  void clearTasks() {
    model.clearTasks();
    updateView();
  }

  void updateView() { view.Render(model.getTasks()); }
};

int main() {
  TaskModel model;
  TaskView view;
  TaskController controller(model, view);

  controller.addTask("Learn MVC");
  controller.addTask("Understand MVP");
  return 0;
}