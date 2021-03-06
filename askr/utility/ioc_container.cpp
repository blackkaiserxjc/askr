#include <askr/utility/ioc_container.h>

namespace askr {

ioc_container::~ioc_container()
{
    destroy();
}

void ioc_container::destroy()
{
    while (!objects_.get<0>().empty())
    {
        objects_.get<0>().back()->destroy(Id());
        objects_.get<0>().pop_back();
    }
    creators_.clear();
}

} // namespace askr