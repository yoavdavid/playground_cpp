#pragma once

namespace david
{
    enum class B
    {
        woot,
    };
}


namespace yoav
{
    using namespace david;

    class A
    {
        B get()
        {
            return B::woot;
        }
    };
}
