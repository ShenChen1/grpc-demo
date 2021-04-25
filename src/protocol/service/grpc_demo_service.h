#ifndef SRC_PROTOCOL_GRPC_DEMO_SERVICE_H
#define SRC_PROTOCOL_GRPC_DEMO_SERVICE_H

#include <memory>

#include "rpc.grpc.pb.h"
#include "grpc_demo_api.h"
#include <grpc++/grpc++.h>

class GrpcDemoService final : protected rpc::Demo::Service
{
public:
	GrpcDemoService(std::unique_ptr<DemoApi> &&dispatcher_ptr);
	GrpcDemoService(const GrpcDemoService &) = delete;
	GrpcDemoService(GrpcDemoService &&) = delete;

	GrpcDemoService &operator=(const GrpcDemoService &) = delete;
	GrpcDemoService &operator=(GrpcDemoService &&) = delete;

	int run();
	void shutdown();

private:
	std::unique_ptr<DemoApi> dispatcher;
	std::unique_ptr<grpc::Server> server;
};

#endif // SRC_PROTOCOL_GRPC_DEMO_SERVICE_H
