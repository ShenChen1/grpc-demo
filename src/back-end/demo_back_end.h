#ifndef SRC_DEMO_BACK_END_API_H
#define SRC_DEMO_BACK_END_API_H

#include "common_back_end.h"
#include "grpc_demo_service.h"

class DemoBackEnd : public CommonBackEnd
{
public:
	DemoBackEnd();
	~DemoBackEnd() override = default;

	DemoBackEnd(const DemoBackEnd &) = delete;
	DemoBackEnd(DemoBackEnd &&) = delete;
	DemoBackEnd &operator=(const DemoBackEnd &) = delete;
	DemoBackEnd &operator=(DemoBackEnd &&) = delete;

public:
	int run() override;

private:
	std::unique_ptr<GrpcDemoService> service;
};

#endif // SRC_DEMO_BACK_END_API_H
