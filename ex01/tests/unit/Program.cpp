#include <Program.hpp>
#include <asserts.hpp>

void test_should_create_a_program_instance()
{
    Program program;

    ASSERT_TRUE(program.isRunning());
}

void RUN_PROGRAM_SUITE()
{
    test_should_create_a_program_instance();
}