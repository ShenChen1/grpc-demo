#ifndef SRC_PROTOCOL_DEMO_CLIENT_H
#define SRC_PROTOCOL_DEMO_CLIENT_H

#include "rpc.grpc.pb.h"
#include "grpc_demo_api.h"

class GrpcDemoClient : public DemoApi
{
public:
	GrpcDemoClient();
	GrpcDemoClient(const GrpcDemoClient &) = delete;
	GrpcDemoClient(GrpcDemoClient &&) = delete;

	GrpcDemoClient &operator=(const GrpcDemoClient &) = delete;
	GrpcDemoClient &operator=(GrpcDemoClient &&) = delete;

	~GrpcDemoClient();

private:
	std::unique_ptr<rpc::Demo::Stub> stub;

public:
	int run(const char *request, char **response) override;
};

#endif // SRC_PROTOCOL_DEMO_CLIENT_H
