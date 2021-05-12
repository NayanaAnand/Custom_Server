#ifndef CUSTOM_SERVER_I_IMPL_H
#define CUSTOM_SERVER_I_IMPL_H

#include "Custom_Server_base.h"

class Custom_Server_i : public Custom_Server_base
{
    ENABLE_LOGGING
    public:
        Custom_Server_i(const char *uuid, const char *label);
        ~Custom_Server_i();

        void constructor();

        int serviceFunction();

    protected:
};

#endif // CUSTOM_SERVER_I_IMPL_H
