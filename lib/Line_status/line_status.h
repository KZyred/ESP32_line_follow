#ifndef _LINE_STATUS_H_
#define _LINE_STATUS_H_

#include <Arduino.h>

class line_status
{
private:
    // mảng chứa vị trí các pin cắm cảm biến
    uint8_t pin[5];
public:
    // hàm tạo (constructor) khởi tạo mảng pin
    line_status(uint8_t pin[5]);

    /* Trạng thái của cảm biến, dữ liệu trả về là:
     *  true  (1) nếu phát hiện line
     *  false (0) nếu không phát hiện line
     */
    bool status[5];  
    
    // Cập nhật trạng thái mới của cảm biến
    void updateLineStatus();

    // lấy sai số (vị trí cảm biến không phát hiện line)
    int8_t getError();
};



#endif