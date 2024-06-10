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

function test_display_all_contacts_when_type_SEARCH_command_and_also_display_new_field_requiring_user_index()
{
    local program_input=$'ADD\n'
         program_input+=$'Douglas\n'
         program_input+=$'Fanucchi\n'
         program_input+=$'sementinha do mau\n'
         program_input+=$'11999999999\n'
         program_input+=$'deu em cima da ex do amigo\n'
         program_input+=$'SEARCH'

    local expected=$'First Name: \n'
         expected+=$'Last Name: \n'
         expected+=$'Nickname: \n'
         expected+=$'Phonenumber: \n'
         expected+=$'Darkest Secret: \n' 
         expected+=$'---------------------------------------------\n'
         expected+=$'|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|\n'
         expected+=$'---------------------------------------------\n'
         expected+=$'|         0|   Douglas|  Fanucchi|sementinh.|\n'
         expected+=$'---------------------------------------------\n'
         expected+=$'User index to display: '

    local result=$(echo "$program_input" | eval $executable)

    ASSERT_STREQ "$expected" "$result"
}

test_exits_program_when_type_EXIT
test_shows_input_fields_to_add_new_contact_when_passes_add_command
test_display_all_contacts_when_type_SEARCH_command_and_also_display_new_field_requiring_user_index
printf \\n