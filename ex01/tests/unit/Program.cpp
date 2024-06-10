#include <Program.hpp>
#include <asserts.hpp>

void test_should_create_a_program_instance()
{
    Program program;

    ASSERT_TRUE(program.isRunning());
}

void test_should_call_run_method_passing_EXIT_command_and_expects_isRunning_to_change()
{
    Program program;

    program.run("EXIT");

    ASSERT_FALSE(program.isRunning());
}

void RUN_PROGRAM_SUITE()
{
    test_should_create_a_program_instance();
    test_should_call_run_method_passing_EXIT_command_and_expects_isRunning_to_change();
}