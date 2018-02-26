// Example usage for CalibrationManager library by Markus Kreitzer.

#include "CalibrationManager.h"

// Initialize objects from the lib
CalibrationManager calibrationManager;

void setup() {
    // Call functions on initialized library objects that require hardware
    calibrationManager.begin();
}

void loop() {
    // Use the library's initialized objects and functions
    calibrationManager.process();
}
