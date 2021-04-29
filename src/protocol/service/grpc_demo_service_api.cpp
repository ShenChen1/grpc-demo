#include "grpc_demo_service.h"

grpc::Status GrpcDemoService::run(
    grpc::ServerContext *,
    const rpc::DemoRequest *request,
    rpc::DemoResponse *response)
{
    std::string prefix("Hello ");
    response->set_response(prefix + request->request());
    return grpc::Status::OK;
}
