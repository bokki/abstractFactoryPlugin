#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <QtPlugin>

//QT_BEGIN_NAMESPACE
//class QWidget;
//QT_END_NAMESPACE

class ProductA;
class ProductB;

class abstractFactory
{
public:
    abstractFactory();
    virtual ~abstractFactory();

public:
    virtual ProductA* createProductA() = 0;
    virtual ProductB* createProductB() = 0;
    virtual void destroyProductA(ProductA*& product) = 0;
    virtual void destroyProductB(ProductB *&product) = 0;
};

QT_BEGIN_NAMESPACE

#define abstractFactory_iid "abstractFactoryExample.abstractFactory"
Q_DECLARE_INTERFACE(abstractFactory, abstractFactory_iid)

QT_END_NAMESPACE


#endif // ABSTRACTFACTORY_H
