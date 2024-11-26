# 客户端常用的架构


## 总体概述

客户端常用的架构包括MVC,MVVM,MVP等这样一些架构，实际上这些架构就是再处理用户交互，数据，UI之间的关系。


## MVC

Model: 负责数据的增删改查
View: 负责显示UI
Controller: 负责处理与用户的交互，然后分别更新Model和View
Model和View之间是解耦合的，通过Controller进行统一调配

## MVP

Model:负责数据的增删改查
View : 负责显示UI,用户通过View中的接口与Presenter沟通，操作Model
Presenter: 负责对数据进行修改，并更新View 

## MVVM

Model: 负责数据的增删改查
ViewModel: 保存了Model数据的缓存，查找的时候可以直接将这个数据返回给View,需要和Model中的数据保持一致
View: 负责显示UI,提供了用户交互接口，并调用ViewModel对数据进行修改，需要用户手动更新此时View


