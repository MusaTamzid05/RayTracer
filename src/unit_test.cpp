#include "unit_test.h"
#include "test_header.h"
#include "test_tuple.h"
#include "test_canvas.h"
#include "test_color.h"
#include "test_matrix.h"
#include "test_ray.h"
#include "test_sphere.h"
#include <iostream>


CPPUNIT_TEST_SUITE_REGISTRATION(Testing::TestCanvas);
CPPUNIT_TEST_SUITE_REGISTRATION(Testing::TestTuple);
CPPUNIT_TEST_SUITE_REGISTRATION(Testing::TestColor);
CPPUNIT_TEST_SUITE_REGISTRATION(Testing::TestMatrix);
CPPUNIT_TEST_SUITE_REGISTRATION(Testing::TestRay);
CPPUNIT_TEST_SUITE_REGISTRATION(Testing::TestSphere);

namespace Testing {

    int run_test() {

        CPPUNIT_NS::TestResult test_result;
        CPPUNIT_NS::TestResultCollector collected_results;
        test_result.addListener(&collected_results);

        CPPUNIT_NS::BriefTestProgressListener progress;
        test_result.addListener(&progress);

        CPPUNIT_NS::TestRunner test_runner;
        test_runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
        test_runner.run(test_result);

        CPPUNIT_NS::CompilerOutputter compiler_outputter(&collected_results , std::cerr);
        compiler_outputter.write();
       
        return collected_results.wasSuccessful() ? 0 : 1;
    }

};
