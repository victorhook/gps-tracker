#ifndef WEB_H
#define WEB_H


#include "vsrtos.h"
#include <WiFiServer.h>
#include <WiFiClient.h>


class Web : public Task {
    public:
        Web(const uint16_t port = 8080);
        int init() override;
        void update() override;
    private:
        bool       _connected_to_wifi;
        bool       _initialized_server;
        bool       _client_connected;
        WiFiServer _server;
};

extern Web web;

#endif /* WEB_H */
