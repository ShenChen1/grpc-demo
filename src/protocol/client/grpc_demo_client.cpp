#include "grpc_demo_client.h"

#include "grpc_common.h"
#include <grpc++/grpc++.h>

GrpcDemoClient::GrpcDemoClient()
    : stub(rpc::Demo::NewStub(
        grpc::CreateChannel(
            grpc_socket_address,
            grpc::InsecureChannelCredentials())
        )
    )
{}