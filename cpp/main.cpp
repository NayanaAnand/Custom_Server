#include <iostream>
#include "ossie/ossieSupport.h"

#include "Custom_Server.h"
int main(int argc, char* argv[])
{
    Custom_Server_i* Custom_Server_servant;
    Component::start_component(Custom_Server_servant, argc, argv);
    return 0;
}

