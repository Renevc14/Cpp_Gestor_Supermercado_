#include "Supermarket.h"
#include "MockDataProvider.h"
#include "TxtDataProvider.h"
using namespace std;
#include <iostream>
#include "App.h"

int main()
{
    App app;
    //app.run();
    DataProvider* dataProvider;
    dataProvider = new MockDataProvider;
    Supermarket supermarket(dataProvider);
    supermarket.menu();

}

