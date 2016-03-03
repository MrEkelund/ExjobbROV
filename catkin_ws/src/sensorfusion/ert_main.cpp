//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ert_main.cpp
//
// Code generated for Simulink model 'sensorfusion'.
//
// Model version                  : 1.288
// Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
// C/C++ source code generated on : Thu Mar  3 10:30:28 2016
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include <stdio.h>
#include <stdlib.h>
#include "sensorfusion.h"
#include "sensorfusion_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
#include "linuxinitialize.h"

static sensorfusionModelClass rtObject;// Instance of model class
volatile boolean_T runModel = 1;
sem_t stopSem;
sem_t termSem;
sem_t baserateTaskSem;
pthread_t terminateThread;
pthread_t schedulerThread;
pthread_t baseRateThread;
unsigned long threadJoinStatus[8];
int terminatingmodel = 0;
int subratePriority[0];
void baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(rtObject.getRTM()) == (NULL));
  while (runModel) {
    sem_wait(&baserateTaskSem);
    rtObject.step();

    // Get model outputs here
    runModel = (rtmGetErrorStatus(rtObject.getRTM()) == (NULL));
  }

  sem_post(&termSem);
  pthread_exit((void *)0);
}

void exitTask(int sig)
{
  rtmSetErrorStatus(rtObject.getRTM(), "stopping the model");
}

void terminateTask(void *arg)
{
  int i;
  int ret;
  sem_wait(&termSem);
  terminatingmodel = 1;
  printf("**terminating the model**\n");
  fflush(stdout);

  // Wait for baseRate task to complete
  ret = pthread_join(baseRateThread, (void *)&threadJoinStatus);
  CHECK_STATUS(ret, 0, "pthread_join");

  // Disable rt_OneStep() here

  // Terminate model
  rtObject.terminate();
  sem_post(&stopSem);
}

int main(int argc, char **argv)
{
  void slros_node_init(int argc, char** argv);
  slros_node_init(argc, argv);
  printf("**starting the model**\n");
  fflush(stdout);
  rtmSetErrorStatus(rtObject.getRTM(), 0);

  // Initialize model
  rtObject.initialize();

  // Call RTOS Initialization funcation
  myRTOSInit(0.2, 0);

  // Wait for stop semaphore
  sem_wait(&stopSem);
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
