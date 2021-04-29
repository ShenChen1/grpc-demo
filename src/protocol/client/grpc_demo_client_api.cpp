#include "grpc_demo_client.h"

int GrpcDemoClient::run(const char *request, char **response)
{
    grpc::ClientContext context;
    rpc::DemoRequest _request;
    rpc::DemoResponse _response;

    _request.set_request(request);
    grpc::Status status = stub->run(&context, _request, &_response);
    if (!status.ok()) {
        std::cerr << "RPC Failed: " << status.error_message() << std::endl;
        return -1;
    }

    *response = strdup(_response.response().c_str());
    return 0;
}
