#include "Particle.h"
#include "CalibrationManager.h"

CalibrationManager::CalibrationManager(){
    //Particle.function("calibrate", &CalibrationManager::update_values, this);
    begin = 0;
}

int CalibrationManager::get_calibration_parameters(){
    EEPROM.get(this->address, this->sensor);
    if(this->sensor.id == 0xFF){
        return false;
    }else{
        return true;
    }
}

int CalibrationManager::convert_args(String *command){
    uint len = command->length();
    char *buf = (char*) malloc(len+1);
    command->toCharArray(buf,len);
    scanf(buf, "%f,%f,%f,%f,%f,%f,%d", &this->cal_data);
    free(buf);
    return true;
}

int CalibrationManager::update_values(String command) {
    //this->convert_args(command);
    EEPROM.put(this->address, this->cal_data);
    return 0;
}
