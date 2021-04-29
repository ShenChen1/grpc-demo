#ifndef SRC_DEMO_BACK_END_API_H
#define SRC_DEMO_BACK_END_API_H

#include "grpc_demo_service.h"

class DemoBackEnd
{
public:
    DemoBackEnd();
    ~DemoBackEnd() = default;

    DemoBackEnd(const DemoBackEnd &) = delete;
    DemoBackEnd(DemoBackEnd &&) = delete;
    DemoBackEnd &operator=(const DemoBackEnd &) = delete;
    DemoBackEnd &operator=(DemoBackEnd &&) = delete;

    int run();

private:
    std::unique_ptr<GrpcDemoService> service;
};

#endif // SRC_DEMO_BACK_END_API_H
