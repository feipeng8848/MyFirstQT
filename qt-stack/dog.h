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
