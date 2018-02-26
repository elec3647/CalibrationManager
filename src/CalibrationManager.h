#pragma once

/* CalibrationManager library by Markus Kreitzer
 */

// This will load the definition for common Particle variable types
#include "Particle.h"

// This is your main class that users will import into their application
class CalibrationManager
{
public:
  /**
   * Constructor
   */
  CalibrationManager();

  /**
   * Example method
   */
  void begin();

  /**
   * Example method
   */
  void process();

private:
  /**
   * Example private method
   */
  void doit();
};
