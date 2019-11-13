#include "dog.h"

Dog::Dog(QObject *parent) : QObject(parent)
{
    this->m_name = "first name";
}

void Dog::setName(QString n){
    this->m_name = n;
    //发射信号
    emit NameChanged();
}

QString Dog::Name(){
    return m_name;
}

void Dog::newName(QString nm){
    setName(nm);
}
