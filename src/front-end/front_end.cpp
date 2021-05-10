#include <memory>
#include <errno.h>

#include "demo_api.h"
#include "grpc_demo_client.h"

namespace {

auto s = std::make_shared<GrpcDemoClient>();

} // namespace

#define RETURN_INVALID_ARG_IF_NULL(param)    \
    do {                                     \
        if ((param) == nullptr)              \
            return -EINVAL; \
    } while (0)

extern "C" {

int demo_run(const char *request, char **response)
{
    RETURN_INVALID_ARG_IF_NULL(request);
    RETURN_INVALID_ARG_IF_NULL(response);
    return s->run(request, response);
}

int demo_run_async(const char *request, char **response)
{
    RETURN_INVALID_ARG_IF_NULL(request);
    RETURN_INVALID_ARG_IF_NULL(response);
    return s->run_async(request, response);
}
}
