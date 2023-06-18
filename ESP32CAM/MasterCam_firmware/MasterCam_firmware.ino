#include <WiFi.h>
//#include <esp_http_server.h>
#include <ESPAsyncWebServer.h>
#include "esp_camera.h"
//#include "esp_timer.h"
//#include "img_converters.h"
#include <Update.h>

const char* ssid = "ProjectSunday";
const char* password = "D34D8YT3";
const char* stream_path = "/stream";
const char* update_path = "/update";

AsyncWebServer server(80);

//httpd_handle_t server = NULL;

//esp_err_t update_handler(httpd_req_t* req) {
//  //Handle OTA update here
//  /// ...
//  return ESP_OK;
//}

//esp_err_t stream_handler(httpd_req_t* req) {
//  camera_fb_t* fb = NULL;
//  esp_err_t res = ESP_OK;
//  
//  fb = esp_camera_fb_get();
//}
  
void setup() {
  // Initialize Serial monitor
  Serial.begin(115200);
  while (!Serial);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize camera
  camera_config_t config;
  // Set camera configuration as per your specific board
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = 5; //Y2_GPIO_NUM;
  config.pin_d1 = 18; //Y3_GPIO_NUM;
  config.pin_d2 = 19; //Y4_GPIO_NUM;
  config.pin_d3 = 21; //Y5_GPIO_NUM;
  config.pin_d4 = 36; //Y6_GPIO_NUM;
  config.pin_d5 = 39; //Y7_GPIO_NUM;
  config.pin_d6 = 34; //Y8_GPIO_NUM;
  config.pin_d7 = 35; //Y9_GPIO_NUM;
  config.pin_xclk = 0; //XCLK_GPIO_NUM;
  config.pin_pclk = 22; //PCLK_GPIO_NUM;
  config.pin_vsync = 25; //VSYNC_GPIO_NUM;
  config.pin_href = 23; //HREF_GPIO_NUM;
  config.pin_sscb_sda = 26; //SIOD_GPIO_NUM;
  config.pin_sscb_scl = 27; //SIOC_GPIO_NUM;
  config.pin_pwdn = 32; //PWDN_GPIO_NUM;
  config.pin_reset = -1; //RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;

  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.println("Camera initialization failed");
    while (1);
  }
  Serial.println("Camera initialized");

  // Start the server
  server.on(stream_path, HTTP_GET, [](AsyncWebServerRequest* request){
    camera_fb_t* fb = esp_camera_fb_get();
    if (!fb) {
      request->send(500, "text/plain", "Camera capture failed");
    } else {
      request->send_P(200, "image/jpeg", fb->buf, fb->len);
      esp_camera_fb_return(fb);
    }
  });

  server.on(update_path, HTTP_POST, [](AsyncWebServerRequest* request){
    AsyncWebServerResponse *response = request->beginResponse(200, "text/plain", (Update.hasError()) ? "Update failed" : "Update successful");
    response->addHeader("Connection", "close");
    request->send(response);
  }, [](AsyncWebServerRequest *request, String filename, size_t index, uint8_t *data, size_t len, bool final){
    if (!index) {
      Serial.println("Updating firmware...");
      if (!Update.begin(UPDATE_SIZE_UNKNOWN)){
        Update.printError(Serial);
      }
    }
    if(Update.write(data, len) != len) {
      Update.printError(Serial);
    }
    if (final) {
      if (Update.end(true)) {
        Serial.println("Firmware update successfully, Rebooting...");
        ESP.restart();
      } else {
        Update.printError(Serial);
      }
    }
  });

  server.begin();
}
  //httpd_config_t http_config = HTTPD_DEFAULT_CONFIG();
  //http_config.uri_match_fn = httpd_uri_match_wildcard;
  //err = httpd_start(&server, &http_config);
  //if (err != ESP_OK) {
  //  Serial.println("Error starting server");
  //  while (1) {}
  //}
  //Serial.println("Server started");

  // Register the stream endpoint
//  httpd_uri_t stream_uri = {
//    .uri = stream_path,
//    .method = HTTP_GET,
//    .handler = stream_handler,
//    .user_ctx = NULL
//  };
//  httpd_register_uri_handler(server, &stream_uri);

  // Register the OTA update endpoint
//  httpd_uri_t update_uri = {
//    .uri = update_path,
//    .method = HTTP_POST,
//    .handler = update_handler,
//    .user_ctx = NULL
//  };
//  httpd_register_uri_handler(server, &update_uri);
//}

void loop() {
  // Handle client requests
  //httpd_handle_t client;
  //while ((client = httpd_accept(server, 0)) != NULL) {
  //  httpd_resp_send_404(client, "Not Found");
 //   httpd_resp_close(client);
 // }
}
