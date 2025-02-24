#define ASIO_STANDALONE
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <iostream>

typedef websocketpp::server<websocketpp::config::asio> server;

int main()
{
    try
    {
        server ws_server;

        // Set logging settings
        ws_server.set_access_channels(websocketpp::log::alevel::all);
        ws_server.clear_access_channels(websocketpp::log::alevel::frame_payload);

        // Initialize ASIO
        ws_server.init_asio();

        std::cout << "WebSocket++ Server initialized" << std::endl;
    }
    catch (websocketpp::exception const &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}