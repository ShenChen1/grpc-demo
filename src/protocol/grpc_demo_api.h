#ifndef SRC_PROTOCOL_GRPC_DEMO_API_H
#define SRC_PROTOCOL_GRPC_DEMO_API_H

class DemoApi
{
public:
	DemoApi() = default;
	virtual ~DemoApi() = default;

	DemoApi(const DemoApi &) = delete;
	DemoApi &operator=(const DemoApi &) = delete;
	DemoApi(DemoApi &&) = delete;
	DemoApi &&operator=(DemoApi &&) = delete;

public:
	virtual int run(const char *request, char **response) = 0;
};

#endif // SRC_PROTOCOL_GRPC_DEMO_API_H
