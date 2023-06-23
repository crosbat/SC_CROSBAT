#ifdef __cplusplus
extern "C" {
#endif

/**
 @code
  ___ _____ _   ___ _  _____ ___  ___  ___ ___
 / __|_   _/_\ / __| |/ / __/ _ \| _ \/ __| __|
 \__ \ | |/ _ \ (__| ' <| _| (_) |   / (__| _|
 |___/ |_/_/ \_\___|_|\_\_| \___/|_|_\\___|___|
 embedded.connectivity.solutions.==============
 @endcode

 @file
 @copyright  STACKFORCE GmbH, Germany, www.stackforce.de
 @author     STACKFORCE
 @brief      A dummy Implementation of the measurement handler interface.
*/

/*=============================================================================
                                INCLUDES
=============================================================================*/
#include <stdbool.h>
#include <string.h>
#include "measHandler_api.h"
#include "lib/random.h"
#include "sf_absoluteTime.h"
#include <ti/drivers/GPIO.h>
#include <ti/drivers/adc.h>
#include "CC26X2R1_LAUNCHXL.h"



/*=============================================================================
                          GLOBAL VARIABLES
=============================================================================*/
/* Measurement storage */
static meas_t gMeas = {0};
/* Measurement type
   false - old
   true - new */
static bool gMeasType = false;

unsigned int en_val = 1; // for making the LED on

ADC_Handle adc;
ADC_Params params;

int_fast16_t res;
uint16_t adcValue;



/*=============================================================================
                          API IMPLEMENTATION
=============================================================================*/
/*------------------------------------------------------------------------------
  measHandler_performMeas()
------------------------------------------------------------------------------*/
__attribute__((weak)) bool measHandler_performMeas(void)
{
  /* Get internal absolute time */
  gMeas.timeStamp = sf_absoluteTime_getTime();

  //MY ADC CODE



//  ADC_Params_init(&params);
//  adc = ADC_open(CC26X2R1_LAUNCHXL_DIO28_ANALOG, &params);
//  if (adc != NULL) {
//      ADC_close(adc);
//  }
//
//
//  res = ADC_convert(adc, &adcValue);
//  if (res == ADC_STATUS_SUCCESS) {
//      //use adcValue
//  }


  ////////

  /* Provide dummy measurement*/
  gMeas.value = random_rand();

  //Make an LED turn-on
  //GPIO_write(IOID_5,en_val);

  /* Set meas as new */
  gMeasType = true;

  return true;
}/* measHandler_performMeas() */

/*------------------------------------------------------------------------------
  measHandler_getMeas()
------------------------------------------------------------------------------*/
__attribute__((weak)) bool measHandler_getMeas(meas_t* pMeas)
{
  if(true == gMeasType)
  {
    /* Map the measurement */
    memcpy(pMeas, &gMeas, sizeof(gMeas));

    /* Set meas as old */
    gMeasType = false;

    return true;
  }

  return false;
}/* measHandler_getMeas() */

/*------------------------------------------------------------------------------
  measHandler_setStatus()
------------------------------------------------------------------------------*/
__attribute__((weak)) void measHandler_setStatus(E_MEAS_STATUS_t status)
{
  switch(status)
  {
    case E_MEAS_TX_SUCCESS:
      /* Nothing to do for now*/
      break;

    case E_MEAS_TX_FAIL:
      /* Nothing to do for now*/
      break;

  default:
    break;
  }
}/* measHandler_setStatus() */


#ifdef __cplusplus
}
#endif