#!/bin/bash

function ASSERT_STREQ()
{
if [[ $1 == $2 ]];
then
    printf ✅
else
    printf ❌
fi
}

executable=$1

function test_exits_program_when_type_EXIT()
{
local expected=""

local result=$(echo -n "EXIT" | eval $executable)

ASSERT_STREQ "$expected" "$result"
}

test_exits_program_when_type_EXIT
printf \\n