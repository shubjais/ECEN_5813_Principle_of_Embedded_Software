/*========================================================================
** ring_test.c
** Circular buffer testing
** ECEN5813
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
CU_ASSERT_NOT_EQUAL(0,MAX);
CU_ASSERT_PTR_NOT_EQUAL(NULL, startaddr);
}

void test_ring_reset()
{
CU_ASSERT_EQUAL(0,startaddr->Ini);
CU_ASSERT_EQUAL(0,startaddr->Outi);
CU_ASSERT_EQUAL(0,startaddr->Buffer_full);
printf("%d\r\n", rand()%50);
}

void test_insert()
{

/*Test the function with insert less than the total buffer size*/
int x = rand()%256; 
insert(startaddr,x);
CU_ASSERT_FALSE(ring_status(startaddr));
CU_ASSERT_NOT_EQUAL(MAX,num);
//CU_ASSERT_EQUAL(1,startaddr->buffer[startaddr->Ini-1%MAX]);

/*Test the function with insert less than the total buffer size*/
x = rand()%256; 
insert(startaddr,x);
CU_ASSERT_FALSE(ring_status(startaddr));
CU_ASSERT_NOT_EQUAL(MAX,num);

/*Test the function with insert equal to the total buffer size*/
x = rand()%256;
insert(startaddr,x);
CU_ASSERT_TRUE(ring_status(startaddr));
CU_ASSERT_EQUAL(MAX,num);
//CU_ASSERT_EQUAL(2,startaddr->buffer[startaddr->Ini-1%MAX]);

/*Test the function with insert more to the total buffer size*/
x = rand()%256;
insert(startaddr,x);
CU_ASSERT_TRUE(ring_status(startaddr));
CU_ASSERT_EQUAL(MAX,num);
//CU_ASSERT_EQUAL(2,startaddr->buffer[startaddr->Ini-1%MAX]);
}

void test_removed()
{
char data1;
/*Test the function with removed less than the total buffer size*/
//removed(startaddr);
remove_data(startaddr, &data1);
CU_ASSERT_TRUE(ring_status(startaddr));
CU_ASSERT_NOT_EQUAL(MAX,num);

/*Test the function with removed less than the total buffer size*/
//removed(startaddr);
remove_data(startaddr, &data1);
CU_ASSERT_TRUE(ring_status(startaddr));
CU_ASSERT_NOT_EQUAL(MAX,num);

/*Test the function with remove equal to the total buffer size*/
//removed(startaddr);
remove_data(startaddr, &data1);
CU_ASSERT_FALSE(ring_status(startaddr));
CU_ASSERT_NOT_EQUAL(MAX,num);
//CU_ASSERT_EQUAL(2,startaddr->buffer[startaddr->Ini-1%MAX]);

/*Test the function with remove more to the total buffer size*/
//removed(startaddr);
remove_data(startaddr, &data1);
CU_ASSERT_FALSE(ring_status(startaddr));
CU_ASSERT_EQUAL(0,num);
//CU_ASSERT_EQUAL(2,startaddr->buffer[startaddr->Ini-1%MAX]);
}

void test_buffer_size()
{
}


/*This function should be tested at the last*/
void test_ring_free()
{
ring_free(startaddr);
//CU_ASSERT_PTR_EQUAL(NULL,startaddr);
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
   if 	((NULL == CU_add_test(pSuite, "Buffer Initialization Test", test_ring_init))||
      	(NULL == CU_add_test(pSuite, "Buffer Reset Test", test_ring_reset))||
      	(NULL == CU_add_test(pSuite, "Buffer Insert Test", test_insert))||
      	(NULL == CU_add_test(pSuite, "Buffer Remove Test", test_removed))||	
      	(NULL == CU_add_test(pSuite, "Buffer Free Test", test_ring_free)))      

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