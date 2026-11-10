# CMake generated Testfile for 
# Source directory: /home/ruhruh66/cpp_stage4/step39
# Build directory: /home/ruhruh66/cpp_stage4/step39/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(AdditionTest "/home/ruhruh66/cpp_stage4/step39/build/add_test")
set_tests_properties(AdditionTest PROPERTIES  _BACKTRACE_TRIPLES "/home/ruhruh66/cpp_stage4/step39/CMakeLists.txt;12;add_test;/home/ruhruh66/cpp_stage4/step39/CMakeLists.txt;0;")
add_test(GoogleTestCheck "/home/ruhruh66/cpp_stage4/step39/build/google_test")
set_tests_properties(GoogleTestCheck PROPERTIES  _BACKTRACE_TRIPLES "/home/ruhruh66/cpp_stage4/step39/CMakeLists.txt;24;add_test;/home/ruhruh66/cpp_stage4/step39/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
