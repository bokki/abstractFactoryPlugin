#include <iostream>
#include <QtPlugin>
#include <QDir>
#include <QStringList>
#include <QPluginLoader>

#include "abstractfactory.h"
#include "producta.h"
#include "productb.h"
#include "factory1.h"
#include "factory2.h"

#include <QDebug>

using namespace std;

int main()
{
//    QDir pluginsDir;
    QStringList pluginFileNames;

    abstractFactory *factoryObj1 = new Factory1();
    ProductA *productObjA1 = factoryObj1->createProductA ();
    ProductB *productObjB1 = factoryObj1->createProductB ();

    productObjA1->show();
    productObjB1->show();

    abstractFactory *factoryObj2 = new Factory2();
    ProductA *productObjA2 = factoryObj2->createProductA ();
    ProductB *productObjB2 = factoryObj2->createProductB ();

    productObjA2->show();
    productObjB2->show();

    QDir pluginsDir("C:/Temp/abstractFactoryExample/plugin");
    qDebug() << "pluginsDir: " << pluginsDir;

    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        qDebug() << "fileName: " << fileName;
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = loader.instance();
        if (plugin)
        {
            abstractFactory *factory = qobject_cast<abstractFactory *>(plugin);
            if (factory)
            {
                pluginFileNames += fileName;
//                abstractFactory *factoryObj3 = new Factory3();
//                ProductA *productObjA3 = factoryObj3->createProductA ();
//                ProductB *productObjB3 = factoryObj3->createProductB ();

//                productObjA3->show();
//                productObjB3->show();
            }
            else
            {
                qDebug() << "Found *.dll plugin, but its not a device: " << fileName;
            }
        }
        else
        {
            qDebug() << "Found fileName in pluginsDir which is not a *.dll: " << fileName;
        }
    }

    factoryObj1->destroyProductA (productObjA1);
    factoryObj1->destroyProductB (productObjB1);
    delete factoryObj1;
    factoryObj1 = 0;
    factoryObj2->destroyProductA (productObjA2);
    factoryObj2->destroyProductB (productObjB2);
    delete factoryObj2;
    factoryObj2 = 0;
    return 0;
}

