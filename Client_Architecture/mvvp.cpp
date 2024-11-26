/**
 * @file mvvp.cpp
 * @brief This is a simple example of the Model-View-ViewModel (MVVM) design
 * @author Tendacia
 * @date 2024-11-26
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Model class for the Task
 *
 */
class TaskModel {
private:
  vector<string> tasks;

public:
  void addTask(const string &task) { tasks.push_back(task); }

  const vector<string> &getTasks() const { return tasks; }
};

/**
 * @brief ViewModel class for the Task
 *
 */
class TaskViewModel {
private:
  TaskModel &model;
  vector<string> tasks;

public:
  TaskViewModel(TaskModel &model) : model(model) {}

  void addTask(const string &task) {
    model.addTask(task); // 更新 Model
    updateTasks();       // 同步数据
  }

  const vector<string> &getTasks() const { return tasks; }

  void updateTasks() {
    tasks = model.getTasks(); // 从 Model 获取数据
  }
};

/**
 * @brief View class for the Task
 *
 */
class TaskView {
private:
  TaskViewModel &viewModel;

public:
  TaskView(TaskViewModel &viewModel) : viewModel(viewModel) {}

  void render() {
    cout << "Task List:" << endl;
    const auto &tasks = viewModel.getTasks();
    for (size_t i = 0; i < tasks.size(); ++i) {
      cout << i + 1 << ": " << tasks[i] << endl;
    }
  }

  void userAddTask() {
    string task;
    cout << "Enter a new task: ";
    getline(cin, task);
    viewModel.addTask(task); // 通知 ViewModel 更新任务
  }
};

int main() {
  TaskModel model;
  TaskViewModel viewModel(model);
  TaskView view(viewModel);

  view.userAddTask();
  view.render();

  view.userAddTask();
  view.render();

  return 0;
}
