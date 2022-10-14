#pragma once

#include <boost/smart_ptr/intrusive_ptr.hpp>
#include "context/Context.hpp"

namespace qp::cl {

class Scope {
protected:
    boost::intrusive_ptr<Context> m_context;
public:
    explicit Scope(Context& context)
        : m_context(&context) {}
    virtual ~Scope() = default;

    bool operator==(const Scope& other) const {
        return m_context.get() == other.m_context.get();
    }
};

}
