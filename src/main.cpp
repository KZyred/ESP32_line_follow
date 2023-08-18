#include <main.h>

// Khởi tạo vị trí chân nối cảm biến 
uint8_t inputPin[5]={26,25,33,32,35};

/* Khởi tạo lớp điều khiển động cơ 
 * Thứ tự tham số: chân động cơ tiến, chân động cơ lùi, 
 * kênh tiến, kênh lùi, tần số (frequency),
 * độ phân giải (resolution)
 */
esp32_motor leftMotor(14,27,5,6,50000,10);
esp32_motor rightMotor(13,12,7,8,50000,10);

// Khởi tạo lớp xử lí sai lệch (dữ liệu đầu vào từ cảm biến)
line_status error(inputPin);

/* Khởi tạo bộ điều khiển PID
 * Thứ tự tham số: hệ số tỉ lệ (Kp), độ lợi tích phân (Ki),
 * độ lợi vi phân (Kd)
 */
PIDcontroller lineFollow(KP,KI,KD);

void setup() {
  // Khởi tạo vi điều khiển với baudrate 9600
  Serial.begin(9600);
}

void loop() {
  // Cập nhật dữ liệu đầu vào từ cảm biến
  error.updateLineStatus();

  // Tính toán đầu ra từ sai lệch 
  lineFollow.calculateOutput(error.getError());

  // Truyền xung PWM vào các động cơ
  // dựa trên dữ liệu đã qua xử lí từ bộ điều khiển PID
  leftMotor.Run(BASE_PWM+lineFollow.output);
  rightMotor.Run(BASE_PWM-lineFollow.output);
}
