#include "user.h"

User::User()
{
  this->setName("");
  this->setAge(0);
}
User::User(std::string name, int age)
{
  QString q_name = QString::fromStdString(name);
  this->setName(q_name);
  this->setAge(age);
}

QString User::Name()
{
  return m_name;
}

void User::setName(QString name)
{
  m_name = name;
  emit NameChanged();
  setMessage(QString("名称改变为:%1").arg(name));
}

int User::Age()
{
  return m_age;
}

void User::setAge(int age)
{
  m_age = age;
  emit AgeChanged();
  setMessage(QString("年龄改变为:%1").arg(age));
}

QString User::Message()
{
    return m_message;
}

void User::setMessage(QString message)
{
    m_message = message;
    emit MessageChanged();
}
void User::editOk()
{
    setMessage("您点击了确定按钮");
}
