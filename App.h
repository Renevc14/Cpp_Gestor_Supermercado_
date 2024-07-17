#pragma once
#include "MockDataProvider.h"
#include "Supermarket.h"

using namespace std;

class App
{
private:
    DataProvider* dataProvider;
public:


App()
        {
            dataProvider = new MockDataProvider();
        }

        void run()
        {
            Supermarket supermarket(dataProvider);
            supermarket.menu();
            
        }

        ~App()
        {
            delete dataProvider;
        }
    };

