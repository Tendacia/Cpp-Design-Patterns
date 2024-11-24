/**
 * @file EmployeeDAO.cpp
 * @brief 相当于这里的是为了完成一个sql命令的执行，需要创建一个连接，然后创建一个命令，然后执行命令，然后读取数据；这里的几个类都是为了完成这个任务
 *        它们之间有一个相互依赖的关系，而各个具体的实现又有较多不同的实现方式
 */


class EmployeeDAO{
    
public:
    vector<EmployeeDO> GetEmployees(){
        SqlConnection* connection =
            new SqlConnection();
        connection->ConnectionString = "...";

        SqlCommand* command =
            new SqlCommand();
        command->CommandText="...";
        command->SetConnection(connection);

        SqlDataReader* reader = command->ExecuteReader();
        while (reader->Read()){

        }

    }
};
