#ifndef FIREBASE_HTTP_CLIENT_H
#define FIREBASE_HTTP_CLIENT_H

#include <string>

#include "Arduino.h"
#include "Stream.h"

struct HttpStatus {
  static const int TEMPORARY_REDIRECT = 307;
};

class FirebaseHttpClient {
 public:
  static FirebaseHttpClient* create();

  virtual void setReuseConnection(bool reuse) = 0;
  virtual void begin(const std::string& url) = 0;
  virtual void begin(const std::string& host, const std::string& path) = 0;

  virtual void end() = 0;

  virtual void addHeader(const std::string& name, const std::string& value) = 0;
  virtual void collectHeaders(const char* header_keys[],
                              const int header_key_count) = 0;
  virtual std::string header(const std::string& name) = 0;

  virtual int sendRequest(const std::string& method, const std::string& data) = 0;

  virtual std::string getString() = 0;

  virtual Stream* getStreamPtr() = 0;

  virtual std::string errorToString(int error_code) = 0;

  virtual bool connected() = 0;

 protected:
  static const uint16_t kFirebasePort = 443;
};

//<--shanmugamss --> Update this Finger print 
// Original Finger Print -  "03:D6:42:23:03:D1:0C:06:73:F7:E2:BD:29:47:13:C3:22:71:37:1B"; // 2020-02
// Updated FingerPrint - "03: 9E: 4F: E6: 83: FC: 40: EF: FC: B2: C5: EF: 36: 0E: 7C: 3C: 42: 20: 1B: 8F"
// Youtube video : https://www.youtube.com/watch?v=082JBZ-Txvo&t=1141s  ( time code : 10:20 )

static const char kFirebaseFingerprint[] ="03:9E:4F:E6:83:FC:40:EF:FC:B2:C5:EF:36:0E:7C:3C:42:20:1B:8F"
     

#endif  // FIREBASE_HTTP_CLIENT_H
