#include "Particle.h"
#include <HttpClient.h>

typedef struct Sensor {
    char id[24];
    int sensor_num;
    float temp[2];
    float y0[2];
    float y100[2];
};

// struct CalibrationData {
//     float moist_calibration_constants[4];
//     float temp_calibration_constants[2];
//     int version;
// };


class CalibrationManager{
  public:
    CalibrationManager();

  private:
    const int begin = 0;
    const int end = EEPROM.length()-1;
    //float calibration_values_moist[4] = { -0.2744, 17645.0, 0.979, 109.22 };
    //float calibration_values_temp[2] = {0.0044, 7.6176};
    // struct CalibrationData cal_data;
    Sensor sensor;
    String CalibrationManager::get_calibration_info(void);
    struct Sensor CalibrationManager::parse_calibaration_parameters(char *json_data);
    int get_calibration_parameters();
    int convert_args(String *command);
    int update_values(String command);
};
