#ifndef SRC_PROTOCOL_GRPC_DEMO_SERVICE_H
#define SRC_PROTOCOL_GRPC_DEMO_SERVICE_H

#include <memory>

#include "rpc.grpc.pb.h"
#include "grpc_demo_api.h"

#include <grpc++/grpc++.h>

class GrpcDemoService final : protected rpc::Demo::Service
{
public:
    GrpcDemoService();
    GrpcDemoService(const GrpcDemoService &) = delete;
    GrpcDemoService(GrpcDemoService &&) = delete;

    GrpcDemoService &operator=(const GrpcDemoService &) = delete;
    GrpcDemoService &operator=(GrpcDemoService &&) = delete;

    ~GrpcDemoService() = default;

    int startup();
    void shutdown();

private:
    std::unique_ptr<grpc::Server> server;

public:
    grpc::Status run(
        grpc::ServerContext *context,
        const rpc::DemoRequest *request,
        rpc::DemoResponse *response) override;
};

#endif // SRC_PROTOCOL_GRPC_DEMO_SERVICE_H
