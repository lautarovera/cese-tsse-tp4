#include "src/case_parser.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"








typedef struct

{

    char *plain_text;

    char *camel_case;

    char *pascal_case;

    char *snake_case;

} example_t;



example_t case_examples[5] = {



    {.plain_text = "Lorem ipsum dolor sit amet",

     .camel_case = "loremIpsumDolorSitAmet",

     .pascal_case = "LoremIpsumDolorSitAmet",

     .snake_case = "lorem_ipsum_dolor_sit_amet"},



    {.plain_text = "consectetur adipiscing elit",

     .camel_case = "consecteturAdipiscingElit",

     .pascal_case = "ConsecteturAdipiscingElit",

     .snake_case = "consectetur_adipiscing_elit"},



    {.plain_text = "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua",

     .camel_case = "sedDoEiusmodTemporIncididuntUtLaboreEtDoloreMagnaAliqua",

     .pascal_case = "SedDoEiusmodTemporIncididuntUtLaboreEtDoloreMagnaAliqua",

     .snake_case = "sed_do_eiusmod_tempor_incididunt_ut_labore_et_dolore_magna_aliqua"},



    {.plain_text = "Ut enim ad minim veniam",

     .camel_case = "utEnimAdMinimVeniam",

     .pascal_case = "UtEnimAdMinimVeniam",

     .snake_case = "ut_enim_ad_minim_veniam"},



    {.plain_text = "quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat",

     .camel_case = "quisNostrudExercitationUllamcoLaborisNisiUtAliquipExEaCommodoConsequat",

     .pascal_case = "QuisNostrudExercitationUllamcoLaborisNisiUtAliquipExEaCommodoConsequat",

     .snake_case = "quis_nostrud_exercitation_ullamco_laboris_nisi_ut_aliquip_ex_ea_commodo_consequat"},

};



void setUp(void)

{

}



void tearDown(void)

{

}



void test_CamelCase(void)

{

    char non_string_literal[128];

    char message[32];

    char *case_result;



    for (int index = 0; index < 5; index++)

    {

        example_t *example = &case_examples[index];

        sprintf(message, "Example %d", (index + 1));



        strcpy(non_string_literal, example->plain_text);



        case_result = camel_case(non_string_literal);

        UnityAssertEqualString((const char*)((example->camel_case)), (const char*)((case_result)), ((message)), (UNITY_UINT)(68));

        free(case_result);

        case_result = 

                     ((void *)0)

                         ;

    }

}



void test_PascalCase(void)

{

    char non_string_literal[128];

    char message[32];

    char *case_result;



    for (int index = 0; index < 5; index++)

    {

        example_t *example = &case_examples[index];

        sprintf(message, "Example %d", (index + 1));



        strcpy(non_string_literal, example->plain_text);



        case_result = pascal_case(non_string_literal);

        UnityAssertEqualString((const char*)((example->pascal_case)), (const char*)((case_result)), ((message)), (UNITY_UINT)(88));

        free(case_result);

        case_result = 

                     ((void *)0)

                         ;

    }

}



void test_SnakeCase(void)

{

    char non_string_literal[128];

    char message[32];

    char *case_result;



    for (int index = 0; index < 5; index++)

    {

        example_t *example = &case_examples[index];

        sprintf(message, "Example %d", (index + 1));



        strcpy(non_string_literal, example->plain_text);



        case_result = snake_case(non_string_literal);

        UnityAssertEqualString((const char*)((example->snake_case)), (const char*)((case_result)), ((message)), (UNITY_UINT)(108));

        free(case_result);

        case_result = 

                     ((void *)0)

                         ;

    }

}
