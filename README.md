# MyFirstQT
## Qt的前后台交互
### context类
创建一个context类，绑定到APP.rootContext。
context类必须要继承自QObject。
使用Q_PROPERTY暴露context类的属性给qml。
从qml中就能把控件的属性与context类的属性绑定在一起。
下面代码就将Name属性暴露给了qml
```c++
#ifndef DOG_H
#define DOG_H

#include <QObject>

class Dog : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString Name READ Name WRITE setName NOTIFY NameChanged)
public:
    explicit Dog(QObject *parent = nullptr);
    void setName(QString n);
    QString Name();

signals:
    void NameChanged();
public slots:
    //想要在qml中被调用，首先要在函数前面添加Q_INVODEBLE
    Q_INVOKABLE void newName(QString nm);

private:
    QString m_name;
};

#endif // DOG_H
```
下面的qml代码把qml中的lable.text绑定到了c++的Dog.Name
```js
Label {
        text: context.Name
        anchors.centerIn: parent
    }
```
经此绑定后，修改后台的dog.Name前台就会同步显示

context类，思想上和wpf的DataCOntext是完全一样的。

#### qml中可以调用context类的方法
```c++
//想要在qml中被调用，首先要在函数前面添加Q_INVODEBLE
    Q_INVOKABLE void newName(QString nm);
```

qml要使用connect把方法与控件的信号连接起来：
```js
    //连接c++函数
    Connections {
        target: button
        //函数名不能以大写字母开头，否则会报错
        //这里修改之后，UI上会同步更新
        onClicked: context.newName("我已经更新了")
    }
```



