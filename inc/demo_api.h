#ifndef INCLUDE_DEMO_API_H
#define INCLUDE_DEMO_API_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

/*!
 * \brief demo_run
 *
 * Run demo
 *
 * \param [in] request - message sent
 * \param [out] response - message received
 */
int demp_run(const char *request, char **response);

#ifdef __cplusplus
}
#endif

#endif // INCLUDE_DEMO_API_H
