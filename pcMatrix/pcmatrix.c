/*
 *  Matrix Task Processor
 *  Based on Operating Systems: Three Easy Pieces by R. Arpaci-Dusseau and A. Arpaci-Dusseau
 * 
 *  Assignment 3 code
 *  Program operates on tasks submitted to the tasks_input directory
 *  Results are created in the tasks_output directory
 *
 *  A bounded buffer is used to store pending tasks
 *  A producer thread reads tasks from the tasks_input directory 
 *  Consumer threads perform tasks in parallel
 *  Program is designed to run as a daemon (i.e. forever) until receiving a request to exit.
 *
 *  This program mimics the client/server processing model without the use of any networking constructs.
 *
 *  Wes J. Lloyd
 *  University of Washington, Tacoma
 *  TCSS 422 - Operating Systems
 *  Spring 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "matrix.h"
#include "tasks.h"
#include "pcmatrix.h"

int main (int argc, char * argv[])
{
  // Uncomment to see example operation of the readtasks() routine
  //readtasks((void *)100);  

  // Uncomment to see example operation of the dotasks() routine
  //dotasks((void *) NULL);

  int tempMS = 500;

  if (argc != 1) {
      tempMS = atoi(argv[1]);
  }
  

  // To do
  pthread_t p1, p2, p3, p4;

  //thread for read tasks
  pthread_create(&p1, NULL, readtasks, tempMS);

  //thread for do tasks
  pthread_create(&p2, NULL, dotasks, NULL);
  pthread_create(&p3, NULL, dotasks, NULL);
  pthread_create(&p4, NULL, dotasks, NULL);

  pthread_join(p1, NULL);
  pthread_join(p2, NULL);
  pthread_join(p3, NULL);
  pthread_join(p4, NULL);

  // Create one or more pthreads for dotasks()
  return 0;
}
