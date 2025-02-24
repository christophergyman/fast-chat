#include <iostream>
#define ASIO_STANDALONE
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

// rename websocketpp to server
typedef websocketpp::server<websocketpp::config::asio> server;

// pass through currenet websocket connection, and message pointer
void on_message(websocketpp::connection_hdl, server::message_ptr msg)
{
    // print out the message payload form ptr
    std::cout << msg->get_payload() << std::endl;
}

int main()
{
    // define print_server
    server print_server;

    // on message call function on message
    print_server.set_message_handler(&on_message);
    print_server.set_access_channels(websocketpp::log::alevel::all);
    print_server.set_error_channels(websocketpp::log::elevel::all);

    // init, listen, and accept packets from network
    print_server.init_asio();
    print_server.listen(9002);
    print_server.start_accept();

    // run the server
    print_server.run();
}
