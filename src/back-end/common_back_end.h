#ifndef SRC_BACK_END_COMMON_BACK_END_H
#define SRC_BACK_END_COMMON_BACK_END_H

class CommonBackEnd
{
public:
    CommonBackEnd() = default;
    virtual ~CommonBackEnd() = default;

    CommonBackEnd(const CommonBackEnd &) = delete;
    CommonBackEnd &operator=(const CommonBackEnd &) = delete;
    CommonBackEnd(CommonBackEnd &&) = delete;
    CommonBackEnd &&operator=(CommonBackEnd &&) = delete;

public:
	virtual int run() = 0;
};

#endif // SRC_BACK_END_COMMON_BACK_END_H
