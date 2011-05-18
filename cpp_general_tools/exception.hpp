// exception.hpp
// ~~~~~~~~~~~~~
// 
// Copyright (C) 2011 Denis Shevchenko (for @ dshevchenko.biz)
//
// Distributed under the Boost Software License, version 1.0
// (see http://www.boost.org/LICENSE_1_0.txt)

#ifndef CPP_GENERAL_TOOLS_EXCEPTION_HPP
#define CPP_GENERAL_TOOLS_EXCEPTION_HPP

#include <stdexcept>
#include <sstream>

namespace cpp_general_tools {

inline void throw_() {}

///////////////////////////////////////////////////////////////////////////////

template< typename Exception >
class exception {
    typedef exception< Exception >  own_type;
    typedef std::ostringstream      os;
private:
    os what_happened;
private:
    struct cleaner {
        explicit cleaner( os& what_happened_ ) : what_happened( what_happened_ ) {}
        ~cleaner() {
            what_happened.str( "" );
            what_happened.clear();
        }
    private:
        os& what_happened;
    };
public:
    template< typename Some >
    own_type& operator<<( const Some& what ) {
        what_happened << what;
        return *this;
    }

    void operator<<( void (*)() ) {
        cleaner cl( what_happened );
        throw Exception( what_happened.str() );
    }
};

///////////////////////////////////////////////////////////////////////////////

typedef exception< std::logic_error >       logic_error_;
typedef exception< std::domain_error >      domain_error_;
typedef exception< std::invalid_argument >  invalid_argument_;
typedef exception< std::length_error >      length_error_;
typedef exception< std::out_of_range >      out_of_range_;
typedef exception< std::runtime_error >     runtime_error_;
typedef exception< std::range_error >       range_error_;
typedef exception< std::overflow_error >    overflow_error_;
typedef exception< std::underflow_error >   underflow_error_;

} // namespace cpp_general_tools

#endif // CPP_GENERAL_TOOLS_EXCEPTION_HPP
