add_test([=[CheckAndTransformTest.TransformOccurs]=]  /Users/rustam/Documents/VSCODE/lastsem/LR1-main/build/main_test [==[--gtest_filter=CheckAndTransformTest.TransformOccurs]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[CheckAndTransformTest.TransformOccurs]=]  PROPERTIES WORKING_DIRECTORY /Users/rustam/Documents/VSCODE/lastsem/LR1-main/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[CheckAndTransformTest.Original]=]  /Users/rustam/Documents/VSCODE/lastsem/LR1-main/build/main_test [==[--gtest_filter=CheckAndTransformTest.Original]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[CheckAndTransformTest.Original]=]  PROPERTIES WORKING_DIRECTORY /Users/rustam/Documents/VSCODE/lastsem/LR1-main/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[CheckAndTransformTest.NoTransformNeeded]=]  /Users/rustam/Documents/VSCODE/lastsem/LR1-main/build/main_test [==[--gtest_filter=CheckAndTransformTest.NoTransformNeeded]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[CheckAndTransformTest.NoTransformNeeded]=]  PROPERTIES WORKING_DIRECTORY /Users/rustam/Documents/VSCODE/lastsem/LR1-main/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[CheckAndTransformTest.EdgeCases]=]  /Users/rustam/Documents/VSCODE/lastsem/LR1-main/build/main_test [==[--gtest_filter=CheckAndTransformTest.EdgeCases]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[CheckAndTransformTest.EdgeCases]=]  PROPERTIES WORKING_DIRECTORY /Users/rustam/Documents/VSCODE/lastsem/LR1-main/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[CheckAndTransformTest.Ones]=]  /Users/rustam/Documents/VSCODE/lastsem/LR1-main/build/main_test [==[--gtest_filter=CheckAndTransformTest.Ones]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[CheckAndTransformTest.Ones]=]  PROPERTIES WORKING_DIRECTORY /Users/rustam/Documents/VSCODE/lastsem/LR1-main/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  main_test_TESTS CheckAndTransformTest.TransformOccurs CheckAndTransformTest.Original CheckAndTransformTest.NoTransformNeeded CheckAndTransformTest.EdgeCases CheckAndTransformTest.Ones)