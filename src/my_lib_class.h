#pragma once

class MyLibClass
{
    public:
        MyLibClass() = default;
        MyLibClass(int argument);
        void print() const;
        int member() const;

    private:
        int member_ = 0;
};
