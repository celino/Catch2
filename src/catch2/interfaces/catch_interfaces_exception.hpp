/*
 *  Created by Phil on 20/04/2011.
 *  Copyright 2011 Two Blue Cubes Ltd. All rights reserved.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef TWOBLUECUBES_CATCH_INTERFACES_EXCEPTION_H_INCLUDED
#define TWOBLUECUBES_CATCH_INTERFACES_EXCEPTION_H_INCLUDED

#include <catch2/interfaces/catch_interfaces_registry_hub.hpp>
#include <catch2/internal/catch_compiler_capabilities.hpp>

#include <string>
#include <vector>

namespace Catch {
    using exceptionTranslateFunction = std::string(*)();

    struct IExceptionTranslator;
    using ExceptionTranslators = std::vector<std::unique_ptr<IExceptionTranslator const>>;

    struct IExceptionTranslator {
        virtual ~IExceptionTranslator();
        virtual std::string translate( ExceptionTranslators::const_iterator it, ExceptionTranslators::const_iterator itEnd ) const = 0;
    };

    struct IExceptionTranslatorRegistry {
        virtual ~IExceptionTranslatorRegistry();

        virtual std::string translateActiveException() const = 0;
    };

} // namespace Catch

extern template class std::unique_ptr<Catch::IExceptionTranslator const>;




#endif // TWOBLUECUBES_CATCH_INTERFACES_EXCEPTION_H_INCLUDED
