#include "demo_back_end.h"

DemoBackEnd::DemoBackEnd()
{
    service = std::make_unique<GrpcDemoService>();
}

int DemoBackEnd::run()
{
    if (!service) {
        return -ENOMEM;
    }

    return service->startup();
}