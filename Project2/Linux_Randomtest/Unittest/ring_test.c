/*========================================================================
** ring_test.c
** Circular buffer testing
** ECEN5813
** Submitted By: Shubham Jaiswal
**========================================================================*/


#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "CUnit/Automated.h"
#include "ring.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


ring_t *startaddr;
time_t t;

int ring_init(void);

int clean_suite(void) 
{
   return 0;
}


/*First Initialization Function*/
int ring_init()
{
   startaddr = init(MAX);
   srand(time(NULL));
   return 0;
}


void test_ring_init()
{
   int r = ring_init();
   CU_ASSERT_NOT_EQUAL(0,MAX);
   CU_ASSERT_PTR_NOT_EQUAL(NULL, startaddr);
}

void test_insert()
{

   int x = rand()%256; 
   CU_ASSERT_EQUAL(insert(startaddr,x), 0);
   CU_ASSERT_FALSE(startaddr->Buffer_full);
   CU_ASSERT_NOT_EQUAL(MAX,num);

   x = rand()%256; 
   CU_ASSERT_EQUAL(insert(startaddr,x), 0);
   CU_ASSERT_FALSE(startaddr->Buffer_full);
   CU_ASSERT_NOT_EQUAL(MAX,num);

   x = rand()%256;
   CU_ASSERT_EQUAL(insert(startaddr,x), 0);
   CU_ASSERT_TRUE(startaddr->Buffer_full);
   CU_ASSERT_EQUAL(MAX,num);

   x = rand()%256;
   CU_ASSERT_EQUAL(insert(startaddr,x), -1);
   CU_ASSERT_TRUE(startaddr->Buffer_full);
   CU_ASSERT_EQUAL(MAX,num);
}


void test_remove_element()
{
   char data1;
   
   CU_ASSERT_EQUAL(remove_element(startaddr, &data1), 0);
   CU_ASSERT_FALSE(startaddr->Buffer_full);
   CU_ASSERT_NOT_EQUAL(MAX,num);

   CU_ASSERT_EQUAL(remove_element(startaddr, &data1), 0);
   CU_ASSERT_FALSE(startaddr->Buffer_full);
   CU_ASSERT_NOT_EQUAL(MAX,num);

   CU_ASSERT_EQUAL(remove_element(startaddr, &data1), 0);
   CU_ASSERT_FALSE(startaddr->Buffer_full);
   CU_ASSERT_EQUAL(0,num);

   CU_ASSERT_EQUAL(remove_element(startaddr, &data1), -1);
   CU_ASSERT_FALSE(startaddr->Buffer_full);
   CU_ASSERT_EQUAL(0,num);
}


int main(void)
{

   if ( CUE_SUCCESS != CU_initialize_registry() )
         return CU_get_error();

   CU_pSuite pSuite=NULL;
   pSuite = CU_add_suite( "CIRCULAR BUFFER TEST", ring_init, clean_suite);

      if ( NULL == pSuite )
      {
         CU_cleanup_registry();
         return -1;
      }

      if ((NULL == CU_add_test(pSuite, "Buffer Initialization Test", test_ring_init))||
      	(NULL == CU_add_test(pSuite, "Buffer Insert Test", test_insert))||
      	(NULL == CU_add_test(pSuite, "Buffer Remove Test", test_remove_element)))      

      {
         CU_cleanup_registry();
         return CU_get_error();
      }

   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();

   CU_set_output_filename("test");
   CU_automated_run_tests();
   CU_cleanup_registry();
   return CU_get_error();

}