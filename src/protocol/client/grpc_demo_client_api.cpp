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

int GrpcDemoClient::run_async(const char *request, char **response)
{
    grpc::ClientContext context;
    rpc::DemoRequest _request;
    rpc::DemoResponse _response;

    _request.set_request(request);

    // The producer-consumer queue we use to communicate asynchronously with the
    // gRPC runtime.
    grpc::CompletionQueue cq;

    // Storage for the status of the RPC upon completion.
    grpc::Status status;

    // stub->PrepareAsyncrun() creates an RPC object, returning
    // an instance to store in "call" but does not actually start the RPC
    // Because we are using the asynchronous API, we need to hold on to
    // the "call" instance in order to get updates on the ongoing RPC.
    std::unique_ptr<grpc::ClientAsyncResponseReader<rpc::DemoResponse>> rpc(
        stub->PrepareAsyncrun(&context, _request, &cq));

    // StartCall initiates the RPC call
    rpc->StartCall();

    // Request that, upon completion of the RPC, "reply" be updated with the
    // server's response; "status" with the indication of whether the operation
    // was successful. Tag the request with the integer 1.
    rpc->Finish(&_response, &status, (void*)1);

    void* got_tag;
    bool ok = false;
    // Block until the next result is available in the completion queue "cq".
    // The return value of Next should always be checked. This return value
    // tells us whether there is any kind of event or the cq_ is shutting down.
    GPR_ASSERT(cq.Next(&got_tag, &ok));

    // Verify that the result from "cq" corresponds, by its tag, our previous
    // request.
    GPR_ASSERT(got_tag == (void*)1);
    // ... and that the request was completed successfully. Note that "ok"
    // corresponds solely to the request for updates introduced by Finish().
    GPR_ASSERT(ok);

    *response = strdup(_response.response().c_str());
    return 0;
}
