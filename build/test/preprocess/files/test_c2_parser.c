#include "src/c2_parser.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"








void setUp(void)

{

}



void tearDown(void)

{

}



void test_c2_parser_rx_cb(void)

{

    char *ptr = "(0001Shola mundo3F)";

    int len = strlen("(0001Shola mundo3F)");



    while (len--)

    {

        c2_parser_rx_cb(*ptr++);

    }



    do {if ((c2_is_new_message)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(25)));}} while(0);

}
