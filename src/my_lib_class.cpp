#include "my_lib_class.h"

#include <spdlog/spdlog.h>

void MyLibClass::print() const
{
    SPDLOG_INFO("MyLibClass Info Level log. member_ = {}", member_);
}

int MyLibClass::member() const
{
    SPDLOG_INFO("MyLibClass custom member getter. member_ = {}", member_);
    return member_;
}

MyLibClass::MyLibClass(int argument): member_(argument)
{
    SPDLOG_INFO("MyLibClass custom constructor. member_ = {}", member_);
}