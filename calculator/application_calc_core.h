#ifndef APPLICATION_CALC_CORE_H
#define APPLICATION_CALC_CORE_H
#include "application_data.h"
#include <memory>

class application_calc_core
{
private:
    std::shared_ptr<application_data> _data;
public:
    void calc();
    application_calc_core(std::shared_ptr<application_data> data) : _data(data) {};
};

#endif // APPLICATION_CALC_CORE_H
