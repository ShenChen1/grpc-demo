#include "grpc_demo_service.h"

#include <iostream>
#include <utility>

#include "grpc_common.h"
#include <grpc++/grpc++.h>
#include <grpc++/ext/proto_server_reflection_plugin.h>
#include <grpc++/health_check_service_interface.h>

GrpcDemoService::GrpcDemoService()
{
}

int GrpcDemoService::startup()
{
    grpc::ServerBuilder builder;

    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();

    builder.AddListeningPort(grpc_socket_address, grpc::InsecureServerCredentials());
    builder.RegisterService(this);

    server = builder.BuildAndStart();
    if (!server) {
        std::cerr << "Failed to start server" << std::endl;
        return -1;
    }

    server->Wait();
    return 0;
}

void GrpcDemoService::shutdown()
{
    server->Shutdown();
}
