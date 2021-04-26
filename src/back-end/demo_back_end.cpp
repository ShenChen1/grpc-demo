#include "demo_back_end.h"

DemoBackEnd::DemoBackEnd()
{
    service = std::make_unique<GrpcDemoService>(nullptr);
}

int DemoBackEnd::run()
{
    if (!service) {
        return -ENOMEM;
    }
    return service->run();
}