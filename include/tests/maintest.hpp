#pragma once

#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <iostream>

#include "util/tests/PointTests.hpp"
#include "util/tests/RectangleTests.hpp"
#include "util/tests/Vector2Tests.hpp"

namespace vulture{

    namespace test{

        int mainTest(){
            using namespace std;
            using namespace CppUnit;
            // informs test-listener about test results
            CPPUNIT_NS::TestResult testresult;
            // register listener for collecting the test-results
            CPPUNIT_NS::TestResultCollector collectedresults;
            testresult.addListener(&collectedresults);
            // register listener for per-test progress output
            CPPUNIT_NS::BriefTestProgressListener progress;
            testresult.addListener(&progress);
            // insert test-suite at test-runner by registry
            CPPUNIT_NS::TestRunner testrunner;
            testrunner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
            testrunner.run(testresult);
            // output results in compiler-format
            CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
            compileroutputter.write ();
            // Output XML for Jenkins CPPunit plugin
            ofstream xmlFileOut("CppUnit_result.xml");
            XmlOutputter xmlOut(&collectedresults, xmlFileOut);
            xmlOut.write();
            // return 0 if tests were successful
            return !collectedresults.wasSuccessful();
        }
    }
}
