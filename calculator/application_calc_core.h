#ifndef APPLICATION_CALC_CORE_H
#define APPLICATION_CALC_CORE_H
#include "application_data.h"
#include <memory>

class application_calc_core
{
public:
    void calc(std::shared_ptr<application_data> data);
    application_calc_core() {};
};

#endif // APPLICATION_CALC_CORE_H
