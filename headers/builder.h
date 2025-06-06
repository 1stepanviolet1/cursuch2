#pragma once


#ifndef _BUILDER_H
#define _BUILDER_H

#include "figure.h"

_DRAWING_BEGIN

class Builder
{
public:
    virtual Figure* get() const noexcept = 0;
    virtual ~Builder() = 0;

};


#define BUILDER(_NAME) _NAME##Builder
#define REF(_NAME) _##_NAME

#define REG_BUILDER_BEGIN(_NAME)                \
    class BUILDER(_NAME) : public Builder       \
    {                                           \
    public:                                     \
        BUILDER(_NAME)()                        \
        : REF(_NAME)(new _NAME) {    }          \
                                                \
        Figure* get() const noexcept override;

#define REG_BUILDER_END(_NAME)                  \
    public:                                     \
        ~BUILDER(_NAME)() override;             \
    private:                                    \
        _NAME *REF(_NAME);                      \
    };

#define REALIZE_BUILDER_DEFAULT_METHODS(_NAME)  \
    Figure*                                     \
    BUILDER(_NAME)::get() const noexcept        \
    { return this->REF(_NAME); }                \
                                                \
    BUILDER(_NAME)::~BUILDER(_NAME)()           \
    { delete this->REF(_NAME); }

_DRAWING_END


#endif // _BUILDER_H

