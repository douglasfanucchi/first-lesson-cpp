#!/bin/bash

function ASSERT_STREQ()
{
if [[ $1 == $2 ]];
then
    printf ✅
else
    printf ❌
    echo -en "\nEXPECTED\n$1\n";
    echo -en "_______________________________________________\n";
    echo -en "RESULT\n$2";
fi
}

executable=$1

function test_exits_program_when_type_EXIT()
{
local expected=""

local result=$(echo -n "EXIT" | eval $executable)

ASSERT_STREQ "$expected" "$result"
}

function test_shows_input_fields_to_add_new_contact_when_passes_add_command()
{
    local expected=$'First Name: \n'
          expected+=$'Last Name: \n'
          expected+=$'Nickname: \n'
          expected+=$'Phonenumber: \n'
          expected+=$'Darkest Secret: ' 

    local result=$(echo "ADD
                        Douglas
                        Fanucchi
                        sementinha do mau
                        11999999999
                        deu em cima da ex do amigo" | eval $executable)

    ASSERT_STREQ "$expected" "$result"
}

test_exits_program_when_type_EXIT
test_shows_input_fields_to_add_new_contact_when_passes_add_command
printf \\n