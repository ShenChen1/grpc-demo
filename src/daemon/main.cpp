#include <iostream>
#include <memory>

#include "demo_back_end.h"

int main(int argc, char **argv)
{
    argc = argc;
    argv = argv;

    std::unique_ptr<CommonBackEnd> backend = std::make_unique<DemoBackEnd>();
    if (!backend) {
        std::cerr << "Backend not initialized! " << std::endl;
        return -ENOMEM;
    }

    return backend->run();
}
