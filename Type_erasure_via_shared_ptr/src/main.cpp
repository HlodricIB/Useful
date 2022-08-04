#include <initializer_list>
#include "type_erasure.h"

int main()
{
    std::shared_ptr<Base> v_p = std::make_shared<H>();
    v_p->handle(std::make_shared<std::vector<std::string>>(std::initializer_list<std::string>{std::string("Hello!")}));
    return 0;
}
