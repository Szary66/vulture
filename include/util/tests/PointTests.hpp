#pragma once

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCase.h>

#include "util/Point.hpp"

namespace vulture{
    namespace test{
        class PointFixture : public CppUnit::TestFixture{
            CPPUNIT_TEST_SUITE(PointFixture);
                CPPUNIT_TEST(arithmetical_test);
            CPPUNIT_TEST_SUITE_END();
        private:
            Point a, b;
        public:
            void arithmetical_test();
        };
    }
}
