#include "factory3.h"
#include "producta3.h"
#include "productb3.h"

Factory3::Factory3()
{

}

Factory3::~Factory3()
{

}

ProductA *Factory3::createProductA()
{
    return new ProductA3();
}

ProductB *Factory3::createProductB()
{
    return new ProductB3();
}

void Factory3::destroyProductA(ProductA *&product)
{
    delete product;
    product = 0;
}

void Factory3::destroyProductB(ProductB *&product)
{
    delete product;
    product = 0;
}

