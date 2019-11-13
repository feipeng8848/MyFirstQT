#include <QObject>
#include<QtGlobal>
#include<iostream>
#include<string>


class User:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString Name READ Name WRITE setName NOTIFY NameChanged)
    Q_PROPERTY(int Age READ Age WRITE setAge NOTIFY AgeChanged)
    Q_PROPERTY(QString Message READ Message WRITE setMessage NOTIFY MessageChanged)
public:
    User();
    User(std::string name,int age);

    QString Name();
    void setName(QString name);

    int Age();
    void setAge(int age);

    QString Message();
    void setMessage(QString message);
signals:
    void NameChanged();
    void AgeChanged();
    void MessageChanged();
public slots:
void editOk();

private :
    QString m_name;
    int m_age;
    QString m_message;
};
