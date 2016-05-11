#ifndef PRODUCTB3_H
#define PRODUCTB3_H

#include <abstractFactoryExample/productb.h>

class ProductB3 : public ProductB
{
public:
    ProductB3();
    ~ProductB3();

public:
    virtual void show();
};


#endif // PRODUCTB3_H
