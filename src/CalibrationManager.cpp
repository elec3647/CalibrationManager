#include "Particle.h"
#include "CalibrationManager.h"

CalibrationManager::CalibrationManager(){
    //Particle.function("calibrate", &CalibrationManager::update_values, this);
    begin = 0;
}

String CalibrationManager::get_calibration_info(void){
  // Headers currently need to be set at init, useful for API keys etc.
    http_header_t headers[] = {
        { "Accept" , "*/*"},
        { NULL, NULL } // NOTE: Always terminate headers will NULL
    };
    http_request_t request;
    http_response_t response;
    request.hostname = "www.auburn.edu";
    request.port = 80;
    request.path = String("/~mak0023/calibration/" + System.deviceID() + ".json");
    http.get(request, response, headers);
    if(response.status == 200){
        return response.body;
    }else{
        // Return some default values. Need to figure out how to add better exception handling here.
        return String("{\"sensor_num\": 0, \"y100\": [0.979, 109.22], \"id\": \"0\", \"temp\": [0.0044, 7.6176], \"y0\": [-0.2744, 17645.0]}");
    }
    //Serial.print("Application>\tResponse status: ");
    //Serial.println(response.status);
    //Serial.print("Application>\tHTTP Response Body: ");
    //Serial.println(response.body);
}

struct Sensor CalibrationManager::parse_calibaration_parameters(char *json_data){
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(json_data);
    struct Sensor my_parsed;
    my_parsed.id = root["id"];
    my_parsed.sensor_num = root["sensor_num"];
    my_parsed.temp[2] = root["temp"];
    my_parsed.y0[2] = root["y0"];
    my_parsed.y100[2] = root["y100"];
    return my_parsed;
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
