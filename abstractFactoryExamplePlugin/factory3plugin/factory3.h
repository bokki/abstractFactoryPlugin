#ifndef FACTORY3_H
#define FACTORY3_H

#include <QObject>
#include <QtPlugin>

class ProductA;
class ProductB;
#include <abstractFactoryExample/abstractfactory.h>

class Factory3 : public QObject, public abstractFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "abstractFactoryExample.abstractFactory" FILE "factory3.json")
    Q_INTERFACES(abstractFactory)

public:
    Factory3();
    ~Factory3();
public:
    virtual ProductA* createProductA();
    virtual ProductB* createProductB();
    virtual void destroyProductA(ProductA*& product);
    virtual void destroyProductB(ProductB*& product);
};


#endif // FACTORY3_H
