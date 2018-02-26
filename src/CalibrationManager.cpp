/* CalibrationManager library by Markus Kreitzer
 */

#include "CalibrationManager.h"

/**
 * Constructor.
 */
CalibrationManager::CalibrationManager()
{
  // be sure not to call anything that requires hardware be initialized here, put those in begin()
}

/**
 * Example method.
 */
void CalibrationManager::begin()
{
    // initialize hardware
    Serial.println("called begin");
}

/**
 * Example method.
 */
void CalibrationManager::process()
{
    // do something useful
    Serial.println("called process");
    doit();
}

/**
* Example private method
*/
void CalibrationManager::doit()
{
    Serial.println("called doit");
}
