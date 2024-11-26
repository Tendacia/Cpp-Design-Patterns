/**
 * @file mvc.cpp
 * @brief This is a simple example of the Model-View-Presenter (MVP) design
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
 * @brief View Interface for the Task
 *
 */
class ITaskView {
public:
  virtual void displayTasks(const vector<string> &tasks) = 0;
  virtual ~ITaskView() = default;
};

/**
 * @breif Presenter class for the Task
 *       This class is responsible for the communication between Model and View,
 * and also the business logic
 *
 */

class TaskPresenter {
private:
  TaskModel &model;
  ITaskView &view;

public:
  TaskPresenter(TaskModel &model, ITaskView &view) : model(model), view(view) {}

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

  void updateView() { view.displayTasks(model.getTasks()); }
};

/**
 * @brief View class for the Task
 *        This class is responsible for the UI of the Task, and handle the user
 * input
 *
 */
class TaskView : public ITaskView {
private:
  TaskPresenter &presenter;

public:
  TaskView(TaskPresenter &presenter) : presenter(presenter) {}

  void displayTasks(const vector<string> &tasks) override {
    cout << "Task List:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
      cout << i + 1 << ": " << tasks[i] << endl;
    }
  }

  void userAddTask() {
    string task;
    cout << "Enter a new task: ";
    getline(cin, task);
    presenter.addTask(task); // 通知 Presenter 处理任务
  }
};

int main() {
  TaskModel model;
  TaskView *view = nullptr;
  TaskPresenter presenter(model, *view);
  view = new TaskView(presenter);
  presenter.updateView();

  view->userAddTask();
  view->userAddTask();

  delete view;
  return 0;
}
